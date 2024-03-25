#include <string>
#include "Item.h"

Item::Item(const std::string &name, const std::string &desc) {
    this->name = name;
    this->description = desc;
}

void Item::Interact() {
    std::cout << "You interacted with " << name << std::endl;
}

std::string Item::GetName() const { return name; }

