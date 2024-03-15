#include <iostream>
#include "spdlog/spdlog.h"
#include "Creational.h"
#include "TestBoost.h"
#include "TestJson.h"

using namespace std;
using namespace testBoost;

int main()
{
    // 使用默认日志器
    auto console_logger = spdlog::default_logger_raw();
    spdlog::info("Welcome to spdlog!");

    return 0;
}