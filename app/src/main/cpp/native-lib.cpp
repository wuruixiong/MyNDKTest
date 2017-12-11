#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_myndktest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring
JNICALL
Java_com_myndktest_MainActivity_myStringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "My C++";
    return env->NewStringUTF(hello.c_str());
}