/* DO NOT EDIT THIS FILE - it is machine generated */
  #include <stdio.h>
  #include <jni.h>
  #include <stdlib.h>
/* Header for class com_example_lynnlee_ndkdemo_JniUtils */

#ifndef _Included_com_example_lynnlee_ndkdemo_JniUtils
#define _Included_com_example_lynnlee_ndkdemo_JniUtils
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_lynnlee_ndkdemo_JniUtils
 * Method:    stringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_lynnlee_ndkdemo_JniUtils_stringFromJNI
  (JNIEnv *, jobject);

/*
 * Class:     com_example_lynnlee_ndkdemo_JniUtils
 * Method:    addFromJNI
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_example_lynnlee_ndkdemo_JniUtils_addFromJNI
  (JNIEnv *, jobject, jint, jint);

#ifdef __cplusplus
}
#endif
#endif