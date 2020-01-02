/*
 * Copyright (c) 2014-2017, Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
#include "mmi_module.h"

/**
* Defined case run in mmi mode,this mode support UI.
*
*/
static const mmi_module_t *g_module = NULL;
static int g_pid = -1;
static exec_cmd_t execmd;

static pthread_mutex_t g_mutex;

#define KEY_WORD_CHANNEL "Channel:"
#define KEY_WORD_ESSID "ESSID:"
#define KEY_WORD_SIGNAL_LEVEL "Signal level"
#define KEY_WORD_SSID "SSID"
#define KEY_WORD_SIGNAL "signal"
#define KEY_WORD_FREQ "freq"
#define KEY_WORD_COMPLETED "COMPLETED"

enum {
    METHOD_NORMAL = 0,
    METHOD_2_4G = 1,
    METHOD_5G = 2,
};

typedef struct {
    char channel[64];
    char essid[64];
    char signal_level[128];
} wifi_info;

static void cb_function(char *str, int size) {
    if(g_module != NULL)
        g_module->cb_print(NULL, SUBCMD_MMI, str, size, PRINT);
}

static void load_driver() {
    char temp[256] = { 0 };
    snprintf(temp, sizeof(temp), "insmod %s", get_value("wifi_driver"));
    system(temp);

    MMI_ALOGI("exec '%s' to load wifi driver", temp);
}

static void unload_driver() {
    system("rmmod wlan");

    MMI_ALOGI("exec 'rmmod wlan' to unload wifi driver");
}

static void config_wlan() {
    char temp[256] = { 0 };
    snprintf(temp, sizeof(temp), "%s wlan0 up", get_value("wifi_ifconfig"));
    system(temp);

    MMI_ALOGI("exec '%s' to config wifi", temp);
}

static int start_test(char *buf, uint32_t size) {
		char result[500 * SIZE_1K] = { 0 };
		char tmp[256] = { 0 };
		wifi_info wifi_result;
		int ret = FAILED;
		bool found = false;
		ALOGE("%s wifi start to test. ", __FUNCTION__);
		if(!check_file_exist(get_value("wifi_driver")) || !check_file_exist(get_value("wifi_ifconfig"))){
		   ALOGE("%s file miss, need check. ", __FUNCTION__);
			return FAILED;
			}
		load_driver();
		config_wlan();
	
		int loop = 0;
		system("/vendor/bin/hw/wpa_supplicant -B -iwlan0 -Dnl80211 -c/vendor/etc/mmi/wpa_supplicant_test.conf -O/data/misc/wifi/sockets -ddd");
		sleep(2);	
		system("wpa_cli -i wlan0 -p /data/misc/wifi/sockets scan");
		sleep(2);
		
	for(loop = 0; loop < 6; loop ++)
		{
			memset(result, 0 ,SIZE_1K);
			memset(buf, 0 ,SIZE_1K);
			   memset(tmp, 0 ,256);
			sleep(5);
			char *args[] = {(char *)"/vendor/bin/wpa_cli", (char *)"-i", (char *)"wlan0", (char *)"-p", (char *)"/data/misc/wifi/sockets", (char *)"stat", NULL};
			execmd.cmd = "/vendor/bin/wpa_cli";
			execmd.params = args;
			execmd.pid = &g_pid;
			execmd.result = result;
			execmd.size = sizeof(result);
			ret = exe_cmd(cb_function, &execmd);
	
	
			if(ret != SUCCESS)
				return FAILED;
	
		char *p = result;
		char *ptr;
	
		while(*p != '\0') { 		/*print every line of scan result information */
			ptr = tmp;
			while(*p != '\n' && *p != '\0') {
				*ptr++ = *p++;
			}
	
			p++;
			*ptr++ = '\n';
			*ptr = '\0';
			strlcat(buf, tmp, size);
			ptr = strstr(tmp, KEY_WORD_COMPLETED);
			if(ptr != NULL) {
				//ptr = strstr(tmp, ":");
				//ptr++;
				//snprintf(tmp, sizeof(tmp), "ESSID: = %s \n", ptr);
				//strlcat(buf, tmp, size);
				found = true;
				unload_driver();
				return SUCCESS;
			}
	
		}
		}
	unload_driver();
	return FAILED;

}

static int32_t module_init(const mmi_module_t * module, unordered_map < string, string > &params) {
    if(module == NULL) {
        MMI_ALOGE("NULL point received");
        return FAILED;
    }
    MMI_ALOGI("module init start for module:[%s]", module->name);

    g_module = module;
    pthread_mutex_init(&g_mutex, NULL);

    MMI_ALOGI("module init finished for module:[%s]", module->name);
    return SUCCESS;
}

static int32_t module_deinit(const mmi_module_t * module) {
    if(module == NULL) {
        MMI_ALOGE("NULL point received");
        return FAILED;
    }
    MMI_ALOGI("module deinit start for module:[%s]", module->name);

    MMI_ALOGI("module deinit finished for module:[%s]", module->name);
    return SUCCESS;
}

static int32_t module_stop(const mmi_module_t * module) {
    if(module == NULL) {
        MMI_ALOGE("NULL point received");
        return FAILED;
    }
    MMI_ALOGI("module stop start for module:[%s]", module->name);

    kill_proc(g_pid);
    //kill_thread(module->run_pid);

    MMI_ALOGI("module stop finished for module:[%s]", module->name);
    return SUCCESS;
}

/**
* Before call Run function, caller should call module_init first to initialize the module.
* the "cmd" passd in MUST be defined in cmd_list ,mmi_agent will validate the cmd before run.
*
*/
static int32_t module_run(const mmi_module_t * module, const char *cmd, unordered_map < string, string > &params) {
    int ret = FAILED;
    int method = METHOD_NORMAL;
    char buf[SIZE_1K] = { 0 };

    if(!module || !cmd) {
        MMI_ALOGE("NULL point received");
        return FAILED;
    }
    MMI_ALOGI("module run start for module:[%s], subcmd=%s", module->name, MMI_STR(cmd));
    g_module = module;

    pthread_mutex_lock(&g_mutex);
    if(!strncmp(params["method"].c_str(), "normal", 6))
        method = METHOD_NORMAL;
    else if(!strncmp(params["method"].c_str(), "2.4G", 4))
        method = METHOD_2_4G;
    else if(!strncmp(params["method"].c_str(), "5G", 2))
        method = METHOD_5G;

    ret = start_test(buf, sizeof(buf));

    MMI_ALOGI("module:[%s] test %s", module->name, MMI_TEST_RESULT(ret));
    pthread_mutex_unlock(&g_mutex);

    if(!strcmp(cmd, SUBCMD_MMI)) {
        module->cb_print(params[KEY_MODULE_NAME].c_str(), SUBCMD_MMI, buf, strlen(buf), PRINT_DATA);
    } else if(!strcmp(cmd, SUBCMD_PCBA)) {
        module->cb_print(params[KEY_MODULE_NAME].c_str(), SUBCMD_PCBA, buf, strlen(buf), PRINT_DATA);
    } else {
        MMI_ALOGE("Received invalid command: %s", MMI_STR(cmd));
    }

    MMI_ALOGI("module run finished for module:[%s], subcmd=%s", module->name, MMI_STR(cmd));
   /** Default RUN mmi*/
    return ret;
}

/**
* Methods must be implemented by module.
*/
static struct mmi_module_methods_t module_methods = {
    .module_init = module_init,
    .module_deinit = module_deinit,
    .module_run = module_run,
    .module_stop = module_stop,
};

/**
* Every mmi module must have a data structure named MMI_MODULE_INFO_SYM
* and the fields of this data structure must be initialize in strictly sequence as definition,
* please don't change the sequence as g++ not supported in CPP file.
*/
mmi_module_t MMI_MODULE_INFO_SYM = {
    .version_major = 1,
    .version_minor = 0,
    .name = "Wifi",
    .author = "Qualcomm Technologies, Inc.",
    .methods = &module_methods,
    .module_handle = NULL,
    .supported_cmd_list = NULL,
    .supported_cmd_list_size = 0,
    .cb_print = NULL, /**it is initialized by mmi agent*/
    .run_pid = -1,
};
