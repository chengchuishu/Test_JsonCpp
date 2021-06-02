//
// Created by 17719242718 on 2020/12/21.
//

#include <cstdio>
#include <string>

#include "json/json.h"


int main(int argc, char* argv[])
{
    // 设置信号回调函数，运行程序后键入ctrl + C回调signal_callback_handler函数
    std::cout <<"==========start service [check] ============\n";

    std::string hello = "Hello from C++";

    Json::Value json;
    json["test"] = "hello";
    json["value"] = "world";
    json["ret"] = 10;

    Json::FastWriter fastWriter;
    std::string strSendJson = fastWriter.write(json);

    std::cout <<strSendJson;

    std::cout <<"==========start service [enter] ============\n";
    return 0;
}