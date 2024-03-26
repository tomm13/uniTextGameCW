#include <string>
#include "Character.h"

Character::Character(const std::string &name, int health) {
    this->name = name;
    this->health = health;
}

void Character::TakeDamage(int damage) {
    this->health -= damage;
}

void Character::AddItem(const Item &item) {
    this->inventory.push_back(item);
}

Player::Player(const std::string &name, int health) : Character(name, health) {}

void Player::SetLocation(Room *room) {
    this->location = room;
}

Room *Player::GetLocation() {
    return this->location;
}

std::vector<Item> Character::GetInventory() {
    return this->inventory;
}
