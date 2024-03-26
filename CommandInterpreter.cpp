#include <iostream>
#include <string>
#include "Character.h"
#include "CommandInterpreter.h"

void CommandInterpreter::interpretCommand(const std::string &command) {
    // Split the command into words and identify the action and optional parameters
    // Tip: You can use std::istringstream for splitting the string
    // Example command processing logic
    if (command == "look") {
        // Player looks around (no action required)
        std::cout << "You look around the room." << std::endl;
    } else {
        if (command == "interact") {
            // Player interacts with an item in the room
            std::cout << "Enter the name of the item you want to interact with: ";
            std::string itemName;
            std::cin >> itemName;
            for (Item& item : this->GetPlayer().GetLocation()->GetItems()) {
                if (item.GetName() == itemName) {
                    item.Interact();
                    this->GetPlayer().GetLocation()->RemoveItem(item);
                    this->GetPlayer().AddItem(item);
                    break;
                }
            }
        } else if (command == "move") {
            // Player moves to another room
            std::cout << "Enter the direction (e.g., north, south): ";
            std::string direction;
            std::cin >> direction;
            Room* nextRoom = this->GetPlayer().GetLocation()->GetExit(direction);
            if (nextRoom != nullptr) {
                this->GetPlayer().move(nextRoom);
                std::cout << "You move to the next room." << std::endl;
            } else {
                std::cout << "You can't go that way." << std::endl;
            }
        } else if (command == "quit") {
            // Quit the game
            std::cout << "Goodbye!" << std::endl;
            exit(0);
        } else if (command == "name") {
            // Quit the game
            std::cout << this->GetPlayer().GetName() << std::endl;
        } else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
}

Player CommandInterpreter::GetPlayer() {
    return *this->player_;
}
