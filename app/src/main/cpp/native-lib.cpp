#include <jni.h>
#include <string>

#include "json/json.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_yunshen_test_1jsoncpp_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    Json::Value json;
    json["test"] = "hello";
    json["value"] = "world";
    json["ret"] = 10;

    Json::FastWriter fastWriter;
    std::string strSendJson = fastWriter.write(json);
    //Json::StreamWriterBuilder fastWriter;
    //std::string strSendJson = Json::writeString(fastWriter, json);


    return env->NewStringUTF(strSendJson.c_str());
}