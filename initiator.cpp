#include <jni.h>
#include "headers/initiator.hpp"

jint Initiator::CreateJVM(JavaVM *jvm, JNIEnv *env)
{
    JavaVMInitArgs vm_args;
    JavaVMOption *options = new JavaVMOption[1];
    options[0].optionString = "-Djava.class.path=.";
    vm_args.version = JNI_VERSION_1_6;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;
    return JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args);
}