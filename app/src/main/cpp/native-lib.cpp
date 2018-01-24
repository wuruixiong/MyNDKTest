#include <jni.h>
#include <stdlib.h>
#include <string>

extern "C" { //告诉编译器，这部分代码按C语言的格式进行编译，而不是C++的

// 需要在 CMakeLists.txt 文件中配置，需要在使用的类中配置System.loadLibrary
// build/intermediates/cmake/ 下会生成对应的 .so 文件

// 在Jni编程中所有本地语言实现Jni接口的方法前面都有一个"JNIEXPORT",这个可以看做是Jni的一个标志，至今为止没发现它有什么特殊的用处。
// 下面这行代码 可以只写jstring，不写JNIEXPORT
// jstring 是jni返回值的一种，详细类型 查看 jni.h
JNIEXPORT jstring
// 这个可以理解为Jni 和Call两个部分，和起来的意思就是 Jni调用XXX（后面的XXX就是JAVA的方法名）
JNICALL
Java_com_myndktest_MainActivity_stringFromJNI(
        // env参数 可以看做是Jni接口本身的一个对象，在上一篇中提到的jni.h头文件中存在着大量被封装好的函数，
        // 这些函数也是Jni编程中经常被使用到的，要想调用这些函数就需要使用JNIEnv这个对象。
        // 例如：env->GetObjectClass()。（详情请查看jni.h）
        JNIEnv *env,
        // jobject参数 需要两种情况分析。
        // Test t=new Test(); t.firstTest();
        // 上段代码中firstTest方法是一个非静态方法，
        // 在Java中要想调用它必须先实例化对象，然后再用对象调用它，那这个时候jobject就可以看做Java类的一个实例化对象，
        // 也就是obj就是t。如果firstTest是一个静态方法，那么在Java中，它不是属于一个对象的，而是属于一个类的，
        // Java中用Test.firstTest()这样的方式来调用，这个时候jobject就可以看做是java类的本身，也就是obj就是Test.class。
        jobject ) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jstring
JNICALL
Java_com_myndktest_MainActivity_myStringFromJNI(
        JNIEnv *env,
        jobject) {
    std::string hello = "My C++";
    return env->NewStringUTF(hello.c_str());
}


int
JNICALL
Java_com_myndktest_MainActivity_myIntFromJNI(
        JNIEnv *env,
        jobject) {
    return 100;
}

}

/*extern "C"
JNIEXPORT jstring
JNICALL
Java_com_myndktest_MainActivity_myStringFromJNI(
        JNIEnv *env,
        jobject *//* this *//*) {
    std::string hello = "My C++";
    return env->NewStringUTF(hello.c_str());
}*/

