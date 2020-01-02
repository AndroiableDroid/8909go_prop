/******************************************************************************
  @file    file_playback.c
  @brief   Android performance iop library contain playback sourcecode

  DESCRIPTION

  ---------------------------------------------------------------------------
  Copyright (c) 2015-2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/



#include "dblayer.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <cutils/log.h>
#include <sys/mman.h>
#include <pthread.h>
#include <cutils/properties.h>
#include <sys/syscall.h>
//#include <linux/ioprio.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>

#undef ATRACE_TAG
#define ATRACE_TAG ATRACE_TAG_ALWAYS
#include <cutils/trace.h>
#define MAX_FILE_SIZE (50*1024*1024) //50MB
#define MAX_TOTAL_DATA (500*1024*1024) // 500MBMB
#define MAX_NUM_FILE 300

#undef LOG_TAG
#define LOG_TAG           "ANDR-IOP_PB"

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


static pthread_t start_playback_pthread_id = 0;

static sigjmp_buf sigbus_jmp;

static void sigbus_handler(int signum) {
    siglongjmp (sigbus_jmp, 1);
}

void* start_playback_thread(void *pkg_name_arg)
{
    file_details *file_detail_ptr;
    int num_file = 0;
    int num_of_files = 0;
    char *pkg_name = (char *)pkg_name_arg;
    int i = 0;
    int total_data = 0;
    struct stat file_stat;
    struct sigaction sigbus_act;

    memset (&sigbus_act, 0, sizeof(sigbus_act));
    // to handle SIGBUS errors during mmap
    sigbus_act.sa_handler = sigbus_handler;
    sigbus_act.sa_flags = SA_SIGINFO;

    ATRACE_BEGIN("start_playback_thread: Enter");

    if (sigaction(SIGBUS, &sigbus_act, NULL)) {
        QLOGI("Not able to configure sigbus handler");
    }

    QLOGI("pkg_name = %s",pkg_name);
    num_file = get_total_file(pkg_name);

    if( num_file <= 0)
    {
        QLOGI("no file to read get_total_file %d", num_file);
        remove_pkg(pkg_name);
        free(pkg_name);
        ATRACE_END();
        return NULL;
    }

    file_detail_ptr = (file_details *) malloc(sizeof(file_details) * num_file);
    if (NULL == file_detail_ptr)
    {
        QLOGI("Fail to allocate memory");
        remove_pkg(pkg_name);
        free(pkg_name);
        ATRACE_END();
        return NULL;
    }

    num_of_files = get_file_list(pkg_name,file_detail_ptr,num_file);
    QLOGI("num_of_files = %d",num_of_files);

    if (num_of_files <= 0)
    {
        QLOGI("no file to read get_file_list");
        remove_pkg(pkg_name);
        free(file_detail_ptr);
        free(pkg_name);
        ATRACE_END();
        return NULL;
    }

    if( num_file > MAX_NUM_FILE)
    {
        num_file = MAX_NUM_FILE;
    }

    for(i = 0; i < num_file;i++)
    {
        static unsigned int  c_int = 0;
        int fd = -1;
        int num_pages = 0;
        int page_ittr = 0;
        char trace_buf[4096];
        char *file_mmap = NULL;

        snprintf(trace_buf,4096,"Opening file %s",file_detail_ptr[i].file_name);
        ATRACE_BEGIN(trace_buf);
        fd = open(file_detail_ptr[i].file_name, O_RDONLY);
        if(fd == -1)
        {
            mark_for_delete(pkg_name,file_detail_ptr[i].file_name);
            ATRACE_END();
            continue;
        }
        if ( fstat( fd, &file_stat ) < 0 )
        {
            QLOGI("fail to get file stat");
            mark_for_delete(pkg_name,file_detail_ptr[i].file_name);
            close(fd);
            ATRACE_END();
            continue;// goto  next file
        }
        if ( file_stat.st_size == 0 )
        {
            // File zie is zero
            mark_for_delete(pkg_name,file_detail_ptr[i].file_name);
            close(fd);
            ATRACE_END();
            continue;// goto  next file
        }
        file_mmap = (char *)mmap(NULL, file_stat.st_size, PROT_READ
                                , MAP_SHARED| MAP_NORESERVE, fd, 0 );
        if ( file_mmap == MAP_FAILED )
        {
            QLOGI("Fail to map the file");
            mark_for_delete(pkg_name,file_detail_ptr[i].file_name);
            close(fd);
            ATRACE_END();
            continue;// goto  next file
        }

        snprintf(trace_buf,4096,"reading file %s size = %d",file_detail_ptr[i].file_name
                                ,(int)file_stat.st_size);
        ATRACE_BEGIN(trace_buf);
        num_pages = (file_stat.st_size + PAGE_SIZE - 1)/ PAGE_SIZE;
        QLOGI("%d. mapping file %s pages = %d size = %d ",i,file_detail_ptr[i].file_name
                                ,num_pages,file_stat.st_size);

        /* Sigbus handler jump point to handle app truncating files & causing
           sigbus fault. File mmap & subsequent truncate of file should be handled
           elsewhere in the IO stack. Allow IOP to handle such errors for now.
        */
        if (sigsetjmp(sigbus_jmp, 1))
        {
            if (munmap(file_mmap, file_stat.st_size)) QLOGI("munmap failed");
            QLOGI("File mmap resulted in SIGBUS");
            QLOGI("Package & Filename causing sigbus: %s -- %s", pkg_name,
                file_detail_ptr[i].file_name);
            mark_for_delete(pkg_name,file_detail_ptr[i].file_name);
            close(fd);
            ATRACE_END();
            ATRACE_END();
            continue;// goto  next file
        }

        for(page_ittr = 0; page_ittr < num_pages ; page_ittr++)
        {

            c_int+= file_mmap[page_ittr*PAGE_SIZE];

            total_data += PAGE_SIZE;
            if(page_ittr*PAGE_SIZE > MAX_FILE_SIZE)
            {
                QLOGI("Max file size limit reached");
                //Stop reading as reach on max file limit
                break;
            }
        }

        if (munmap(file_mmap, file_stat.st_size)) QLOGI("munmap failed");
        ATRACE_END();
        ATRACE_END();

        close(fd);
        if(total_data > MAX_TOTAL_DATA)
        {
            QLOGI("Max total size limit reached Total = %d",total_data);
            //STOP reading and max total reached
            break;
        }
    }


    ATRACE_END();
    QLOGI(" Total Data = %d",total_data);
    free(pkg_name);
    free(file_detail_ptr);
    return NULL;
}

void start_playback(char *pkg_name_arg) {
    char *pkg_name = NULL;
    int len = 0;
    QLOGE(" start_playback-1 ");

    if(NULL == pkg_name_arg)
        return;

    len = strlen(pkg_name_arg);
    if(len <= 0)
    {
        QLOGW("Incorrect length for pkg_name_arg");
        return;
    }

    pkg_name = (char *) malloc(len + 1);
    if (NULL == pkg_name)
        return;

    QLOGI(" %s %d\n", pkg_name,strlen(pkg_name));

    strlcpy(pkg_name, pkg_name_arg,len+1);

    if(pthread_create(&start_playback_pthread_id, NULL, start_playback_thread, pkg_name)) {
         return ;
    }
    QLOGI("Exit playback");
    return ;
}

void stop_playback()
{
    QLOGI("Stop Playback ENTER");
    pthread_join(start_playback_pthread_id, (void **)NULL);
    QLOGI("Stop Playback EXIT");
}
