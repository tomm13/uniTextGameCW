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
    std::cout << "Inventory size before: " << this->inventory.size() << std::endl;
    this->inventory.push_back(item);
    std::cout << "Tried to add to inv " << item.GetName() << std::endl;
    std::cout << "Inventory size after: " << this->inventory.size() << std::endl;
}

std::vector<Item> Character::GetInventory() {
    return this->inventory;
}

std::string Character::GetName() {
    return this->name;
}

Player::Player(const std::string &name, int health) : Character(name, health) {

}

void Player::SetLocation(Room *room) {
    std::cout << "Player is trying to move to " << room->GetDescription() << std::endl;
    this->location = room;
}

Room *Player::GetLocation() {
    return this->location;
}

void Player::move(Room *nextRoom) {
    // Implement movement logic
    this->location = nextRoom;
    //this->SetLocation(nextRoom);
    std::cout << "Player should be moving to " <<nextRoom->GetDescription() << std::endl;
}
// Add methods for other actions like pickUpItem(), lookAround(), etc.
