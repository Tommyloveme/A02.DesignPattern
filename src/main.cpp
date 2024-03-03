#include <iostream>
#include "spdlog/spdlog.h"
#include "Creational.h"

/*
    // 使用默认日志器
    auto console_logger = spdlog::default_logger_raw();
    spdlog::info("Welcome to spdlog!");
*/

using namespace DP;

int main() {
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

    return 0;
}