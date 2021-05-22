#include "headers/hasher.hpp"

void Hasher::hash(const char input[])
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
    jint rc = JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args);

    if (rc != JNI_OK)
    {
        exit(EXIT_FAILURE);
    }

    jclass cls = env->FindClass("hasher");

    if (cls != nullptr)
    {
        jmethodID mid = env->GetStaticMethodID(cls, "printHash", "(Ljava/lang/String;)Ljava/lang/String;");

        if (mid != nullptr)
        {
            jstring hashFinalJ = (jstring)env->CallStaticObjectMethod(cls, mid, env->NewStringUTF(input));
            const char *hashFinalC = env->GetStringUTFChars(hashFinalJ, NULL);
            std::string str = std::string(hashFinalC);
            std::cout << str << std::endl;
        }
    }

    jvm->DestroyJavaVM();
}