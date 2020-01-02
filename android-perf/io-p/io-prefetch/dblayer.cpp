/******************************************************************************
  @file    dblayer.c
  @brief   Source file to database of files

  DESCRIPTION

  ---------------------------------------------------------------------------

  Copyright (c) 2015-2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/

/******************************************************************************
     pkg_file_tbl               pkg_tbl
  |-----------------|      |-----------------|
  |  pkg_name       |      |  pkg_name       |
  |  file_name      |      |-----------------|
  |-----------------|      | pkg_use_time    |
  |                 |      | num_of_launches |
  | file_use_ctr    |      |-----------------|
  | file_time_stamp |
  | file_size       |
  | mark_for_delete |
  |-----------------|
******************************************************************************/

#define ATRACE_TAG ATRACE_TAG_ALWAYS

#include "dblayer.h"
#include "string.h"
#include <cutils/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include "sqlite3.h"
#include "maintain_db.h"

#undef LOG_TAG
#define LOG_TAG           "ANDR-IOP_DB"

#if QC_DEBUG
#define QLOGE(...)    ALOGE(__VA_ARGS__)
#define QLOGW(...)    ALOGW(__VA_ARGS__)
#define QLOGI(...)    ALOGI(__VA_ARGS__)
#define QLOGV(...)    ALOGV(__VA_ARGS__)
#else
#define QLOGE(...)
#define QLOGW(...)
#define QLOGI(...)
#define QLOGV(...)
#endif

#define _SQLITE_CHECK(stmt, rt) \
    if (rt != stmt) { \
        QLOGE("\n %s:%d: reason:%s", __FILE__, __LINE__, sqlite3_errmsg(db_conn)); \
        QLOGE(" \n in error code \n");\
        sem_post(&mutex);\
        return 0; \
    }

#define _SQLITE_TRANSACTION_CHECK(stmt, rt) \
    if (rt != stmt) { \
        QLOGE("\n %s:%d: reason:%s", __FILE__, __LINE__, sqlite3_errmsg(db_conn)); \
        sqlite3_exec(db_conn, "ROLLBACK TRANSACTION;", NULL, NULL, NULL);\
        sem_post(&mutex);\
        return 0; \
    }

#define _SQLITE_CHECK_DONE(stmt) _SQLITE_CHECK(stmt, SQLITE_DONE)
#define _SQLITE_CHECK_OK(stmt) _SQLITE_CHECK(stmt, SQLITE_OK)
#define _SQLITE_CHECK_TRANSACTION_OK(stmt) _SQLITE_TRANSACTION_CHECK(stmt, SQLITE_OK)

/* database queries */


#define IO_PREFETCHER_QUERY_CREATE_TBL_FILE_LIST "CREATE TABLE IF NOT EXISTS io_pkg_file_tbl( \
pkg_name TEXT , \
file_name TEXT,\
file_use_counter INTEGER,\
file_time_stamp INTEGER,\
file_size INTEGER,\
mark_for_delete INTEGER,\
PRIMARY KEY(pkg_name,file_name)\
)"

#define IO_PREFETCHER_QUERY_CREATE_TBL_PKG_LIST  "CREATE TABLE IF NOT EXISTS io_pkg_tbl( \
 pkg_name TEXT PRIMARY KEY, \
 pkg_last_use DATETIME, \
 pkg_use_count INTEGER \
 )"

#define IO_PREFETCHER_QUERY_REMOVE_PACKAGE_PKG_TBL   "DELETE from io_pkg_tbl WHERE pkg_name = '%s';\
 DELETE from io_pkg_file_tbl\
 WHERE pkg_name = '%s'"

#define IO_PREFETCHER_QUERY_REMOVE_PACKAGE_FILE_TBL  "DELETE from io_pkg_file_tbl \
 WHERE pkg_name = '%s' AND \
 file_name = '%s'"

#define IO_PREFETCHER_QUERY_MARK_FOR_DELETE      "UPDATE io_pkg_file_tbl \
  SET mark_for_delete = 1\
  WHERE pkg_name = '%s'\
  AND (file_name = '%s')"

#define IO_PREFETCHER_QUERY_DELETE_MARK_FILE     "DELETE from io_pkg_file_tbl \
WHERE mark_for_delete = 1"

#define IO_PREFETCHER_QUERY_TOTAL_PKG            "SELECT COUNT(pkg_name) \
AS num_of_pkg \
FROM io_pkg_tbl"

#define IO_PREFETCHER_QUERY_TOTAL_FILE "SELECT COUNT(file_name) \
 AS num_of_file \
 FROM io_pkg_file_tbl \
 WHERE pkg_name = '%s'"

#define IO_PREFETCHER_QUERY_GET_FILE_LIST "SELECT * FROM io_pkg_file_tbl \
  WHERE pkg_name = '%s' \
  ORDER BY file_time_stamp ASC"

#define IO_PREFETCHER_QUERY_GET_PKG_LIST "SELECT * FROM io_pkg_tbl ORDER BY pkg_last_use"

#define IO_PREFETCHER_QUERY_GET_FILE "select * from io_pkg_file_tbl where pkg_name='%s'\
  AND (file_name = '%s')"

#define IO_PREFETCHER_QUERY_UPDATE_FILE_DETAILS  "UPDATE io_pkg_file_tbl \
 SET \
 file_use_counter = file_use_counter+1\
 ,file_time_stamp = %d\
 ,file_size = %d\
 WHERE pkg_name = '%s' AND (file_name = '%s')"

#define IO_PREFETCHER_QUERY_INSER_FILE "INSERT INTO io_pkg_file_tbl (pkg_name,file_name\
,file_use_counter\
,file_time_stamp\
,file_size\
,mark_for_delete)\
VALUES ('%s','%s',1,%d,%d,0)"

#define IO_PREFETCHER_QUERY_GET_PKG "SELECT * FROM io_pkg_tbl WHERE pkg_name='%s'"

#define IO_PREFETCHER_QUERY_UPDATE_PKG_DETAILS  "UPDATE io_pkg_tbl \
SET pkg_last_use = %lu\
,pkg_use_count = pkg_use_count+1 \
WHERE pkg_name = '%s'"

#define IO_PREFETCHER_QUERY_INSERT_PKG "INSERT INTO io_pkg_tbl (pkg_name,\
  pkg_last_use,\
  pkg_use_count)\
  VALUES ('%s',%lu,1)"

sqlite3 *db_conn = NULL;     // database connection object
sem_t mutex;
char    _dbpath[] = "/data/vendor/iop/io-prefetcher.db"; // database path

/* Private API */
int create_database();
static int open_db();
static int close_database();

//Open database connection
static int open_db()
{
    // don't allow opening up more than one database connection

    if( db_conn != NULL )
    {
      QLOGI( "Already Opened database connection");
      return 1;
    }
    // open the database connection
    int rc = sqlite3_open(_dbpath, &db_conn );
    QLOGI("sqlite3_open db_conn = %p rc = %d \n",db_conn,rc);

    if( db_conn == NULL || rc != SQLITE_OK)
    {
        QLOGI("unable to open database at this path=\"%s\" with sql err_msg=%s"
                     " sql ret code=%d", _dbpath, sqlite3_errmsg(db_conn),rc);

      return 0;
    }
    QLOGI( "db=%s has been opened successful", _dbpath);
    return 1;
}

int create_database()
{
    int fd = -1;

    if(db_conn != NULL)
    {
        // As DB is already init no need to do anything
        return 0;
    }

    fd = open(_dbpath, O_CREAT,600);

    if(fd < 0)
    {
        QLOGI("fail to create database");
        return -1;
    }

    close(fd);

    int conn_status = open_db();
    QLOGI("\n open DB %d \n", conn_status);

    if(conn_status != 1)
    {
        ALOGI("fail to open DB");
        return -1;
    }
    else
    {
        if( db_conn == NULL )
        {
          QLOGI("fail to create DB");
            return -1;
        }
        sem_init(&mutex, 0, 1);
        //create table
        QLOGI("executing Query");
        _SQLITE_CHECK_OK(sqlite3_exec(db_conn, IO_PREFETCHER_QUERY_CREATE_TBL_FILE_LIST, NULL,NULL,NULL));
        _SQLITE_CHECK_OK(sqlite3_exec(db_conn, IO_PREFETCHER_QUERY_CREATE_TBL_PKG_LIST, NULL,NULL,NULL));
        close_database();
    }
    db_maintainer_init();
    return 0;
}

// Close data base connection
static int close_database()
{
  // db already closed?
  if( db_conn == NULL ) return -1;

  int rc = sqlite3_close(db_conn);
  if( rc != SQLITE_OK )
  {
    QLOGI("unable to close database=%s with sql err_msg=%s sql ret code=%d",
                   _dbpath, sqlite3_errmsg(db_conn),rc);
    return -1;
  }
  db_conn = NULL;

  QLOGI( "db=%s has been closed successfully", _dbpath);
  return 0;
}

int clean_db()
{
    //TBD
    // This function is not needed so far
    // may need to revisit in V2
    return 0;
}

//=============================================================================
// Get list of file for given package
int get_file_list(char *pkg_name, file_details *file_info_list, int size)
{
    int count=0;
    char *error=NULL;
    sqlite3_stmt *stmt=NULL;
    char query_str[1024] = IO_PREFETCHER_QUERY_GET_FILE_LIST;
    snprintf(query_str, sizeof(query_str), IO_PREFETCHER_QUERY_GET_FILE_LIST, pkg_name);
    QLOGI("Query = %s", query_str);
    if (NULL == db_conn) open_db();

    sem_wait(&mutex); \
    _SQLITE_CHECK_OK(sqlite3_prepare_v2(db_conn, query_str,
                strlen(query_str), &stmt, (const char**)&error));

    while (sqlite3_step(stmt)==SQLITE_ROW) {
        //fill field
        const char *temp_str = (const char *)sqlite3_column_text(stmt, 1);
        if(temp_str == NULL)
        {
            sqlite3_reset(stmt);
            sqlite3_finalize(stmt);
            sem_post(&mutex);
            return -1;
        }
        snprintf(file_info_list[count].file_name, sizeof(file_info_list[count].file_name), "%s"
                                                , temp_str);
        file_info_list[count].file_use_counter = sqlite3_column_int(stmt, 2);
        file_info_list[count].filesize = sqlite3_column_int(stmt, 3);
        file_info_list[count].file_time_stamp = sqlite3_column_int(stmt, 4);
        count++;
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    sem_post(&mutex); 
    return count;
}

//===========

// Get total number of file
int get_total_file(char * pkg_name)
{
    char query_str[1024] = IO_PREFETCHER_QUERY_TOTAL_FILE;
    int num_files = 0;
    char *error=NULL;
    sqlite3_stmt *stmt=NULL;

    snprintf(query_str,sizeof(query_str),IO_PREFETCHER_QUERY_TOTAL_FILE,pkg_name);

    if(NULL == db_conn) open_db();

    sem_wait(&mutex);

    _SQLITE_CHECK_OK(sqlite3_prepare_v2(db_conn, query_str,
                strlen(query_str), &stmt, (const char**)&error));

    while (sqlite3_step(stmt)==SQLITE_ROW) {
        num_files = sqlite3_column_int(stmt, 0);
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    sem_post(&mutex);

    return num_files;
}

//===========
// Get total number of packages
int get_total_pkgs()
{
    char query_str[1024] = IO_PREFETCHER_QUERY_TOTAL_PKG;
    int num_pkg = 0;
    char *error=NULL;
    sqlite3_stmt *stmt=NULL;

    if(NULL == db_conn) open_db();

    sem_wait(&mutex);

    _SQLITE_CHECK_OK(sqlite3_prepare_v2(db_conn, query_str,
                strlen(query_str), &stmt, (const char**)&error));

    while (sqlite3_step(stmt)==SQLITE_ROW) {
        num_pkg = sqlite3_column_int(stmt, 0);
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    sem_post(&mutex);

    return num_pkg;
}
//=============================================================================

// to get the list of packages
int get_pkg_list(pkg_details *pkg_list_ptr,int size)
{
    char query_str[1024] = IO_PREFETCHER_QUERY_GET_PKG_LIST;
    int num_pkg;
    char *error=NULL;
    sqlite3_stmt *stmt=NULL;
    int counter = 0;

    if(NULL == db_conn)
        open_db();


    sem_wait(&mutex);

    _SQLITE_CHECK_OK(sqlite3_prepare_v2(db_conn, query_str,
                strlen(query_str), &stmt, (const char**)&error));

    while (sqlite3_step(stmt)==SQLITE_ROW && counter < size) {
        const char *temp_str = (const char *)sqlite3_column_text(stmt, 0);
        if(temp_str == NULL)
        {
            sqlite3_reset(stmt);
            sqlite3_finalize(stmt);
            sem_post(&mutex);
            return -1;
        }
        strlcpy(pkg_list_ptr[counter].pkg_name, temp_str,PKG_NAME_LEN);
        pkg_list_ptr[counter].last_time_launched = sqlite3_column_int(stmt, 1);
        pkg_list_ptr[counter].num_launches = sqlite3_column_int(stmt, 2);
        counter++;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    sem_post(&mutex);

    return counter;
}

int iop_query_exec(const char * query_str)
{
    char * error;
    sqlite3_stmt *stmt=NULL;

    QLOGI("queries = %s\n",query_str);
    if(NULL == db_conn) open_db();

    sem_wait(&mutex);

    _SQLITE_CHECK_OK(sqlite3_prepare_v2(db_conn, query_str,
                strlen(query_str), &stmt, (const char**)&error));

    _SQLITE_CHECK_DONE(sqlite3_step(stmt));

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    sem_post(&mutex);

    return 0;
}

//==========================
// Remove package from databae
int remove_pkg(char *pkg_name)
{
    char pkg_query_str[2048] = IO_PREFETCHER_QUERY_REMOVE_PACKAGE_PKG_TBL;

    snprintf(pkg_query_str,sizeof(pkg_query_str),IO_PREFETCHER_QUERY_REMOVE_PACKAGE_PKG_TBL,pkg_name,pkg_name);

    return  iop_query_exec(pkg_query_str);
}

//==========================
// Remove file from databae
int remove_file(char *pkg_name,char* file_name)
{
    char query_str[1024] = IO_PREFETCHER_QUERY_REMOVE_PACKAGE_FILE_TBL;
    snprintf(query_str,sizeof(query_str),IO_PREFETCHER_QUERY_REMOVE_PACKAGE_FILE_TBL,pkg_name,file_name);
    return  iop_query_exec(query_str);
}

//=====================
// Mark any file for delete so can be cleanup in next ittr
int mark_for_delete(char * pkg_name,char * file_name)
{
    char query_str[1024] = IO_PREFETCHER_QUERY_MARK_FOR_DELETE;

    snprintf(query_str,sizeof(query_str),IO_PREFETCHER_QUERY_MARK_FOR_DELETE
                                        ,pkg_name
                                        ,file_name);
   return  iop_query_exec(query_str);

    return 0;
}

//=====================
// Delete all the marked file for deletion
int delete_mark_files()
{
    return  iop_query_exec(IO_PREFETCHER_QUERY_DELETE_MARK_FILE);
}

// update detail for file with provided attibutes
int update_file_details(char * pkg_name,file_details *file_info[], int size)
{
    int i = 0;
    char query_str[2048] = IO_PREFETCHER_QUERY_UPDATE_FILE_DETAILS;

    for(i=0;i<size;i++)
    {

        file_details temp_file_info;
        int is_file_present  = get_file(pkg_name, file_info[i]->file_name, &temp_file_info);
        char * error;
        sqlite3_stmt *stmt=NULL;

        if(is_file_present)
        {
            //Update

            snprintf(query_str,sizeof(query_str),IO_PREFETCHER_QUERY_UPDATE_FILE_DETAILS
                                                ,file_info[i]->file_time_stamp
                                                ,file_info[i]->filesize
                                                ,pkg_name
                                                ,file_info[i]->file_name);
            QLOGI("\nQuery = %s \n",query_str);
            sem_wait(&mutex);
            _SQLITE_CHECK_OK(sqlite3_prepare_v2(db_conn, query_str,
                            strlen(query_str), &stmt, (const char **)&error));

            _SQLITE_CHECK_DONE(sqlite3_step(stmt));
            sqlite3_reset(stmt);
            sqlite3_finalize(stmt);
            sem_post(&mutex);
        }
        else
        {
            //Insert

            snprintf(query_str,sizeof(query_str),IO_PREFETCHER_QUERY_INSER_FILE
                                                ,pkg_name,file_info[i]->file_name
                                                ,file_info[i]->file_time_stamp
                                                ,file_info[i]->filesize
                                                );
            QLOGI("\nQuery = %s \n",query_str);
            sem_wait(&mutex);
            _SQLITE_CHECK_OK(sqlite3_prepare_v2(db_conn, query_str,
                            strlen(query_str), &stmt, (const char **)&error));

            _SQLITE_CHECK_DONE(sqlite3_step(stmt));
            sqlite3_reset(stmt);
            sqlite3_finalize(stmt);
            sem_post(&mutex);
        }
    }
     return 0;
}

//Update package deails with provided attributes
int update_pkg_details(pkg_details pkg_info)
{
    char query_str[2048] = IO_PREFETCHER_QUERY_UPDATE_PKG_DETAILS;
    pkg_details temp_pkg_info;
    temp_pkg_info.pkg_name[0] = 0;
    int is_file_present  =  get_package(pkg_info.pkg_name, &temp_pkg_info);
    QLOGI("update_pkg_details");

    if(NULL == db_conn)
        open_db();

    if(is_file_present)
    {
        //Update
        snprintf(query_str,sizeof(query_str),IO_PREFETCHER_QUERY_UPDATE_PKG_DETAILS
                                            ,pkg_info.last_time_launched
                                            ,pkg_info.pkg_name);
        QLOGI("\nQuery = %s \n",query_str);
        iop_query_exec(query_str);
    }
    else
    {
        //Insert
        snprintf(query_str,sizeof(query_str),IO_PREFETCHER_QUERY_INSERT_PKG
                                            ,pkg_info.pkg_name
                                            ,pkg_info.last_time_launched
                                            );

        QLOGI("\nQuery = %s \n",query_str);
        iop_query_exec(query_str);
    }
    return 0;
}

//=============================================================================

int get_file(char *pkg_name, char *file_name, file_details *file_info)
{
    char query_str[2048] = IO_PREFETCHER_QUERY_UPDATE_PKG_DETAILS;
    char * error;
    sqlite3_stmt *stmt=NULL;
    int count = 0;
    snprintf(query_str,sizeof(query_str),IO_PREFETCHER_QUERY_GET_FILE,pkg_name,file_name);
    QLOGI("queries = %s\n",query_str);
    if(NULL == db_conn) open_db();

    sem_wait(&mutex);

    _SQLITE_CHECK_OK(sqlite3_prepare_v2(db_conn, query_str,
                strlen(query_str), &stmt, (const char**)&error));

    while (sqlite3_step(stmt)==SQLITE_ROW) {

        //fill field
        snprintf(file_info->file_name, sizeof(file_info->file_name), "%s"
                                     , (const char *)sqlite3_column_text(stmt, 1));
        file_info->file_use_counter = sqlite3_column_int(stmt, 2);
        file_info->filesize = sqlite3_column_int(stmt, 3);
        file_info->file_time_stamp = sqlite3_column_int(stmt, 4);
        count++;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    sem_post(&mutex);
    return count;
}

//=============================================================================
int get_package(char *pkg_name, pkg_details *pkg_info)
{

    char query_str[1024] = IO_PREFETCHER_QUERY_GET_PKG;
    char * error;
    sqlite3_stmt *stmt=NULL;
    int count = 0;

    snprintf(query_str,sizeof(query_str),IO_PREFETCHER_QUERY_GET_PKG,pkg_name);
    QLOGI("\n get_file %s \n",query_str);
    if(NULL == db_conn) open_db();

    sem_wait(&mutex);

    _SQLITE_CHECK_OK(sqlite3_prepare_v2(db_conn, query_str,
                strlen(query_str), &stmt, (const char**)&error));

    while (sqlite3_step(stmt)==SQLITE_ROW) {
        const char *temp_str =(const char *)sqlite3_column_text(stmt, 0);
        if(temp_str == NULL)
        {
            sqlite3_reset(stmt);
            sqlite3_finalize(stmt);
            sem_post(&mutex);
            return -1;
        }
        strlcpy(pkg_info->pkg_name, temp_str,PKG_NAME_LEN);
        pkg_info->last_time_launched = sqlite3_column_int(stmt, 1);
        pkg_info->num_launches = sqlite3_column_int(stmt, 2);
        count++;
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    sem_post(&mutex);

    return count;
}
