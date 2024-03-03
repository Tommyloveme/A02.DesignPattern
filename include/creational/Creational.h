#ifndef CREATIONAL_HEADER
#define CREATIONAL_HEADER

#include<vector>

namespace DP {

enum Direction {
    North = 0,
    South,
    East,
    West
};

class MapSite {
public:
    virtual void Enter() = 0;
};

class Room : public MapSite {
public:
    Room(int roomNo);

    MapSite* GetSide(Direction) const;
    void SetSide(Direction, MapSite*);

    virtual void Enter();

protected:
    MapSite* m_mapSite[4];
    int m_roomNo;
};

class Wall : public MapSite {
public:
    Wall();

    virtual void Enter();
};

class Door : public MapSite {
public:
    Door(Room* = 0, Room* = 0);

    virtual void Enter();

    Room* OtherSideFrom(Room*);

protected:
    Room* m_room1;
    Room* m_room2;
    bool m_isOpen;
};

class Maze {
public:
    Maze();

    void AddRoom(Room*);
    Room* RoomNo(int) const;

protected:
    std::vector<Room*> m_Rooms;
};

class MazeGame {
public:
    MazeGame();

    Maze* CreateMaze();

protected:
    Maze* m_Maze;
};

} // namespace DP

#endif