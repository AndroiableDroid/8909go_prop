LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	mp-ctl/perflock_native_test.cpp

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libdl \
	libutils \
	liblog \
	libqti-util \
	libperfgluelayer \
	libqti-perfd

LOCAL_C_INCLUDES := \
	vendor/qcom/proprietary/android-perf/perf-hal \
	vendor/qcom/proprietary/android-perf/perf-util \
	vendor/qcom/proprietary/android-perf/mp-ctl \
	vendor/qcom/proprietary/android-perf/tests

LOCAL_CFLAGS := \
	-Wall \
	-DQTI_DEBUG=0

LOCAL_MODULE := perflock_native_test
include $(BUILD_NATIVE_TEST)


include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	mp-ctl/perflock_native_stress_test.cpp

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libdl \
	libutils \
	liblog \
	libqti-util \
	libperfgluelayer \
	libqti-perfd

LOCAL_C_INCLUDES := \
	vendor/qcom/proprietary/android-perf/perf-hal \
	vendor/qcom/proprietary/android-perf/perf-util \
	vendor/qcom/proprietary/android-perf/mp-ctl \
	vendor/qcom/proprietary/android-perf/tests

LOCAL_CFLAGS := \
	-Wall \
	-DQTI_DEBUG=0

LOCAL_MODULE := perflock_native_stress_test
include $(BUILD_NATIVE_TEST)
