#ifndef SPRINGCOURSEWORK_CHARACTER_H
#define SPRINGCOURSEWORK_CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include "Item.h"

class Character {
private:
    std::string name;
    int health;
    std::vector<Item> inventory;
public:
    Character(const std::string& name, int health);
    void TakeDamage(int damage);
};
class Player : public Character {
private:
    Room* location{};
public:
    Player(const std::string& name, int health);
    void SetLocation(Room* room);
    Room* GetLocation();
};

#endif