#include <jni.h>

class Initiator
{
public:
    jint CreateJVM(JavaVM *jvm, JNIEnv *env);
};