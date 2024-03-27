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

void Area::VisualizeMap(const std::string &filename){
    // first we read through the rooms and their exits and count how many rooms there are in each direction
    // of the starting room
    // for example, if the starting room has exits to the north, south, east, and west, we will have 1 room in each direction
    // using this, we can determine the size of the visualized map, which will be a 2D array
    // this will be heavily aided by the GetExit function in Room.cpp
    // we will then print out the map with the starting room in the center
    // a room will be represented by [] and the player will be represented by X
    // the player will be placed in the center of the map
    // the map will be printed out in the console
    // connections to other rooms will either be represented by a line or a dash (| or -)
    // fixed map size of 5x5
    // fillsize means the size of the map including the connections
    int size = 5;
    int fullSize = 2 * size - 1;
    // create a map of size 9x9 (to allow space for connections)
    std::string map[fullSize][fullSize];


    // fill the map with nullptrs
    for (int i=0; i<fullSize; i++) {
        for (int j=0; j<fullSize; j++) {
            map[i][j] = "  ";
        }
    }

    map[size - 1][size - 1] = "[X]";

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> components;
        std::string component;
        while (std::getline(iss, component, ',')) {
            components.push_back(component);
        }
        int offsetx = 0;
        int offsety = 0;
        if (components[0] == "startroom") {
            if (components[2] == "east") {
                map[offsety + size - 1][offsetx + size + 1] = "[ ]";
                std::cout << "east" << std::endl;
            } else if (components[2] == "west") {
                map[offsety + size - 1][offsetx + size - 3] = "[ ]";
                std::cout << "west" << std::endl;
            } else if (components[2] == "north") {
                map[offsety + size + 1][offsetx + size - 1] = "[ ]";
                std::cout << "north" << std::endl;
            } else if (components[2] == "south") {
                map[offsety + size - 3][offsetx + size - 1] = "[ ]";
                std::cout << "south" << std::endl;
            }
        }
    }

    // key algorithm for mapping the rooms
    // if a room exists, and the room east of it exists, then there is a horizontal connection
    // if a room exists, and the room south of it exists, then there is a vertical connection
    for (int i=0; i<fullSize-2; i=i+2) {
        for (int j=0; j<fullSize-2; j=j+2) {
            if (map[i][j] != "  " and map[i][j+2] != "  ") {
                map[i][j+1] = "--";
            }
            if (map[i][j] != "  " and map[i+2][j] != "  ") {
                map[i+1][j] = " |";
            }
        }
    }

    // print out the map
    for (int i=0; i<fullSize; i++) {
        for (int j=0; j<fullSize; j++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}