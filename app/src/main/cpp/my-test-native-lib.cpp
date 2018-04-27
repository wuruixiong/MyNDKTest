#include <jni.h>
#include <stdlib.h>
#include <string>

extern "C" {

int counter = 0;

JNIEXPORT jstring
JNICALL
Java_com_myndktest_MainActivity_stringFromJNI2(
        JNIEnv *env,
        jobject) {
    std::string hello = "Hello 2 from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jstring
JNICALL
Java_com_myndktest_MainActivity_myStringFromJNI2(
        JNIEnv *env,
        jobject) {
    std::string hello = "My test2 C++";
    return env->NewStringUTF(hello.c_str());
}


int
JNICALL
Java_com_myndktest_MainActivity_myIntFromJNI2(
        JNIEnv *env,
        jobject) {
    counter++;
    return counter;
}

}

