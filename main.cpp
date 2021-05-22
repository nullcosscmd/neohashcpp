#include <iostream>
#include <jni.h>

using namespace std;

int main()
{
    JavaVM *jvm;
    JNIEnv *env;

    JavaVMInitArgs vm_args;
    JavaVMOption *options = new JavaVMOption[1];
    options[0].optionString = "-Djava.class.path=.";
    vm_args.version = JNI_VERSION_1_6;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;
    jint rc = JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args); // YES !!

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
        jmethodID mid = env->GetStaticMethodID(cls, "printHash", "()V");

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