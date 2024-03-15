// #include "Creational.h"
// #include "gtest/gtest.h"

// using namespace std;
// using namespace DP;

// class TestCreational : public testing::Test
// {
//     void SetUp() {}

//     void TearDown() {}
// };

// void TestMazeGame()
// {
//     MazeGame* mazeGame = new MazeGame();
//     Maze* maze = mazeGame->CreateMaze();

//     int num = 0;
//     while (num >= 0) {
//         std::cout << "Enter a number: ";
//         std::cin >> num;
//         std::cout << "You entered: " << num << std::endl;

//         Room* room = maze->RoomNo(num);
//         room->Enter();
//     }
// }

// TEST_F(TestCreational, main)
// {
//     TestMazeGame();
// }