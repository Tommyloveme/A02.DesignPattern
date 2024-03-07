#include <iostream>
#include "spdlog/spdlog.h"
#include "Creational.h"
// #include "TestBoost.h"
#include "EnumDefine.h"
#include "EnumDefine2.h"

using namespace DP;
using namespace std;
using namespace testBoost;

void TestCreational()
{
    MazeGame* mazeGame = new MazeGame();
    Maze* maze = mazeGame->CreateMaze();

    int num = 0;
    while (num >= 0) {
        std::cout << "Enter a number: ";
        std::cin >> num;
        std::cout << "You entered: " << num << std::endl;

        Room* room = maze->RoomNo(num);
        room->Enter();
    }
}

void TestVoid()
{
    cout << ToString(Enum1::Value1) << endl;
    cout << ToString(Enum2::Value1) << endl;
}

int main()
{
    // 使用默认日志器
    auto console_logger = spdlog::default_logger_raw();
    spdlog::info("Welcome to spdlog!");

    TestVoid();
    return 0;
}