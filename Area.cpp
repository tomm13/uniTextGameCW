#include "Area.h"
#include <vector>
#include <fstream>
#include <sstream>

void Area::AddRoom(const std::string &name, Room *room) {
    // adds a room to the area using the name as the key
    rooms[name] = room;
}

void Area::ConnectRooms(const std::string &room1Name, const std::string &room2Name, const std::string &direction) {
    // connects two rooms using a specified direction (north, south, east, west)
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
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Create a stringstream from the line
        std::istringstream iss(line);

        // Vector to store components
        std::vector<std::string> components;

        // Split the line using comma as delimiter
        std::string component;
        while (std::getline(iss, component, ',')) {
            components.push_back(component);
        }
        // prevent duplicate rooms by filtering names
        // rules about game_map.txt
        // the very first room on the map is the starting room
        // the second component is the room that the first room is connected to
        // the third component is the direction that the first room is connected to the second room
        // so whilst the second component can be new, the first component must be an existing room
        if (rooms.find(components[0]) == rooms.end()) {
            this->AddRoom(components[0], new Room(components[0]));
        }
        this->AddRoom(components[1], new Room(components[1]));
        this->ConnectRooms(components[0], components[1], GetOppositeDirection(components[2]));
        std::cout << "Room " << components[0] << " connected to " << components[1] << " in direction " << components[2] << std::endl;
    }

    file.close();
    std::cout << "Map loaded successfully!" << std::endl;
}

Room *Area::GetRoom(const std::string &name) {
    return rooms[name];
}

