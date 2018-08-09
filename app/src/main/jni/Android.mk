LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := native-dynamic-lib
LOCAL_SRC_FILES =: jni-utils.c
include $(BUILD_SHARED_LIBRARY)