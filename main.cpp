#include <iostream>
#include <jni.h>
#include "headers/initiator.hpp"

using namespace std;

int main()
{
    JavaVM *jvm;
    JNIEnv *env;
    Initiator init;

    jint rc = init.CreateJVM(jvm, env);
    if (rc != JNI_OK)
    {
        exit(EXIT_FAILURE);
    }

    cout << "JVM load succeeded: Version ";
    jint ver = env->GetVersion();
    cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

    jclass cls = env->FindClass("test");

    if (cls == nullptr)
    {
        cerr << "ERROR: CLASS NOT FOUND";
    }
    else
    {
        cout << "Class found" << endl;

        jmethodID mid = env->GetStaticMethodID(cls, "mymain", "()V");
        if (mid == nullptr)
        {
            cerr << "ERROR: METHOD NOT FOUND" << endl;
        }
        else
        {
            env->CallStaticVoidMethod(cls, mid);
            cout << endl;
        }
    }

    jvm->DestroyJavaVM();
    cout << "Destroyed Java VM!" << endl;
}