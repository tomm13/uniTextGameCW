#include "Area.h"
#include <vector>

void Area::AddRoom(const std::string &name, Room *room) {
    // adds a room to the area using the name as the key
    rooms[name] = room;
}

void Area::ConnectRooms(const std::string &room1Name, const std::string &room2Name, const std::string &direction) {
    // connects two rooms using a specified direction (north, south, east, west)
    // DIRECTION SYSTEM, 1 = north, 2 = east, 3 = south, 4 = west
    Room* room1 = rooms[room1Name];
    Room* room2 = rooms[room2Name];

    room1->AddExit(GetOppositeDirection(direction), room2);
    room2->AddExit(direction, room1);
}


std::string Area::GetOppositeDirection(const std::string &direction) {
    // returns the opposite direction based on the input direction
    if (direction == "north") {
        return "south";
    } else if (direction == "south") {
        return "north";
    } else if (direction == "east") {
        return "west";
    } else if (direction == "west") {
        return "east";
    } else {
        return "Invalid direction";
    }
}

void Area::LoadMapFromFile(const std::string &filename) {

}

Room *Area::GetRoom(const std::string &name) {
    return nullptr;
}

