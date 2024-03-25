#include <string>
#include <map>
#include "Room.h"

Room::Room(const std::string& desc) {
    this->description = desc;
}

void Room::AddItem(const Item &item) {
    this->items.push_back(item);
}

void Room::RemoveItem(const Item& item) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->GetName() == item.GetName()) {
            items.erase(it); //
            return;
        }
    }
}

void Room::AddExit(const std::string &direction, Room *room) {
    exits.insert({direction, room});
}

std::string Room::GetDescription() const {
     return this->description;
}

std::vector<Item> Room::GetItems() {
    return this->items;
}

Room *Room::GetExit(const std::string& direction) {
    // check every exit in the room based on direction
    for (auto & exit : exits) {
        if (exit.first == direction) {
            return exit.second;
        }
    }
    return nullptr;
}

