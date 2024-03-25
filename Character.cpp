#include <string>
#include "Character.h"

Character::Character(const std::string &name, int health) {
    this->name = name;
    this->health = health;
}

void Character::TakeDamage(int damage) {
    this->health -= damage;
}

Player::Player(const std::string &name, int health) : Character(name, health) {

}

void Player::SetLocation(Room *room) {
    this->location = room;
}

Room *Player::GetLocation() {
    return this->location;
}
