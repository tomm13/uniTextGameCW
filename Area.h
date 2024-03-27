#ifndef SPRINGCOURSEWORK_AREA_H
#define SPRINGCOURSEWORK_AREA_H

#include <string>
#include <map>
#include "Room.h"

class Area {
private:
    std::map<std::string, Room*>rooms;
public:
    void AddRoom(const std::string& name, Room* room);
    Room* GetRoom(const std::string& name);
    void ConnectRooms(const std::string& room1Name, const std::string& room2Name, const std::string& direction);
    void LoadMapFromFile(const std::string& filename);
    void VisualizeMap(const std::string& filename);
    static std::string GetOppositeDirection(const std::string &direction);
};

#endif
