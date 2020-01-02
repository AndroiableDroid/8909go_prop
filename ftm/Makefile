#CC := $(ATH_CROSS_COMPILE_TYPE)gcc
TARGET_TYPE ?= AR9888
TARGET_VERS ?= v2

all:
	$(CC) $(CFLAGS) $(LDFLAGS) -g3 -Wall  \
		ftm_main.c ftm_wlan.c ftm_write_to_flash.c -o ftm

clean:
	rm -f ftm
