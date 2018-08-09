//
// Created by LynnLee on 2018/8/9.
//
#include "native-dynamic-lib.h"

jstring native_get_String(JNIEnv *env, jobject obj){
    return (*env)->NewStringUTF(env, "LynnLee");
}

/*
 * Class:     com_example_lynnlee_ndkdemo_JniUtils
 * Method:    addFromJNI
 * Signature: (II)I
 */
jint native_add(JNIEnv *env, jobject obj, jint a, jint b){
  return a + b;
}


static JNINativeMethod gMethods[] = { {
    "stringFromJNI", "()Ljava/lang/String;", (void *) native_get_String },
    {"addFromJNI", "(II)I", (void *) native_add } };

//System.loadLibrary会自动调用JNI_OnLoad，在此进行动态注册
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved) {
  JNIEnv *env = NULL;
  jint result = JNI_FALSE;

  //获取env指针
  if ((*jvm)->GetEnv(jvm, (void**) &env, JNI_VERSION_1_6) != JNI_OK) {
      return result;
  }
  if (env == NULL) {
      return result;
  }
  //获取类引用，写类的全路径（包名+类名）。FindClass等JNI函数将在后面讲解
  jclass clazz = (*env)->FindClass(env, "***/***/JniUtils");
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

