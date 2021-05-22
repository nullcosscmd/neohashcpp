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

    jclass cls = env->FindClass("test");

    if (cls == nullptr)
    {
        cerr << "ERROR: CLASS NOT FOUND";
    }
    else
    {
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