package com.example.lynnlee.ndkdemo;

public class JniUtils {

    /**
     * 加载so库或jni库
     */
    static {
        System.loadLibrary("native-dynamic-lib");
    }

    public static native String stringFromJNI();
}
