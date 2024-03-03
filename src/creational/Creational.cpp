#include "Creational.h"
#include <iostream>

using namespace std;
using namespace DP;

Room::Room(int roomNo)
{
    this->m_roomNo = roomNo;
}

MapSite* Room::GetSide(Direction direction) const
{
    return this->m_mapSite[direction];
}

void Room::SetSide(Direction direction, MapSite* mapSite)
{
    this->m_mapSite[direction] = mapSite;
}

void Room::Enter()
{
    m_mapSite[m_roomNo]->Enter();
}

Wall::Wall()
{}

void Wall::Enter()
{
    std::cout << "This is Wall" << std::endl;
}

Door::Door(Room* room1, Room* room2)
{
    this->m_room1 = room1;
    this->m_room2 = room2;
}

void Door::Enter()
{
    std::cout << "This is Door" << std::endl;
}

Room* Door::OtherSideFrom(Room* curRoom)
{
    if (curRoom == this->m_room1) {
        return this->m_room2;
    } else {
        return this->m_room1;
    }
}

Maze::Maze()
{}

void Maze::AddRoom(Room* room)
{
    this->m_Rooms.push_back(room);
}

Room* Maze::RoomNo(int roomNo) const
{
    return m_Rooms[roomNo];
}

MazeGame::MazeGame()
{}

Maze* MazeGame::CreateMaze()
{
    Maze* aMaze = new Maze;
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Room* r3 = new Room(3);
    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);
    aMaze->AddRoom(r3);

    r1->SetSide(North, new Wall);
    r1->SetSide(South, new Wall);
    r1->SetSide(East, new Door);
    r1->SetSide(West, new Wall);
    r2->SetSide(North, new Wall);
    r2->SetSide(South, new Wall);
    r2->SetSide(East, new Door);
    r2->SetSide(West, new Wall);
    r3->SetSide(North, new Wall);
    r3->SetSide(South, new Wall);
    r3->SetSide(East, new Wall);
    r3->SetSide(West, new Wall);
    return aMaze;
}