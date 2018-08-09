//
// Created by LynnLee on 2018/8/9.
//
#include <stdio.h>
#include <jni.h>
#include <stdlib.h>

static jstring JNICALL native_get_String(JNIEnv *env, jobject obj) {
    return (*env)->NewStringUTF(env, "LynnLee");
}


static const JNINativeMethod gMethods[] = {
        {"stringFromJNI", "()Ljava/lang/String;", (jstring *) native_get_String}
};

//System.loadLibrary会自动调用JNI_OnLoad，在此进行动态注册
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved) {
    JNIEnv *env = NULL;//注册时在JNIEnv中实现的，所以必须首先获取它
    jint result = JNI_FALSE;

    //获取env指针
    if ((*jvm)->GetEnv(jvm, (void **) &env, JNI_VERSION_1_6) != JNI_OK) {//从JavaVM获取JNIEnv，使用1.6的版本
        return result;
    }

    //获取类引用，写类的全路径（包名+类名）
    jclass clazz = (*env)->FindClass(env, "com.example.lynnlee.ndkdemo.JniUtils");
    if (clazz == NULL) {
        return result;
    }

    //注册方法
    if ((*env)->RegisterNatives(env, clazz, gMethods, sizeof(gMethods) / sizeof(gMethods[0])) < 0) {
        return result;
    }
    //成功
    result = JNI_VERSION_1_6;
    return result;
}

