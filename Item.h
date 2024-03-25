#ifndef SPRINGCOURSEWORK_ITEM_H
#define SPRINGCOURSEWORK_ITEM_H

#include <iostream>
#include <string>

class Item {
private:
    std::string name;
    std::string description;
public:
    Item(const std::string& name, const std::string& desc);
    void Interact();
    std::string GetName() const;;
    std::string GetDescription() const { return description; }
};

#endif

