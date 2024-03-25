#ifndef SPRINGCOURSEWORK_ROOM_H
#define SPRINGCOURSEWORK_ROOM_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Item.h"

class Room {
private:
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<Item> items;
public:
    Room(const std::string& desc);
    void AddItem(const Item& item);
    void RemoveItem(const Item& item);
    void AddExit(const std::string& direction, Room* room);
    std::string GetDescription() const;
    std::vector<Item> GetItems();
    Room *GetExit(const std::string& direction);
};

#endif
