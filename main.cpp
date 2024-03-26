#include <iostream>
#include <vector>
#include <map>
#include "Room.h"
#include "Character.h"
#include "Area.h"


int main() {;
    Area *area = new Area();
    area->LoadMapFromFile("/Users/thomasmok/CLionProjects/AnotherCoursework/game_map.txt");
    Player player("Alice", 100);
    player.SetLocation(area->GetRoom("startroom"));

    std::cout << "Welcome to the game!" << std::endl;

    while (true) {
        std::cout << "Current Location: " << player.GetLocation()->GetDescription() << std::endl;
        std::cout << "Items in your inventory:" << std::endl;
        for (const Item& item : player.GetInventory()) {
            std::cout << "- " << item.GetName() << ": " <<
                      item.GetDescription() << std::endl;
        }
        std::cout << "Items in the room:" << std::endl;
        for (const Item& item : player.GetLocation()->GetItems()) {
            std::cout << "- " << item.GetName() << ": " <<
                      item.GetDescription() << std::endl;
        }
        std::cout << "Options: ";
        std::cout << "1. Look around | ";
        std::cout << "2. Interact with an item | ";
        std::cout << "3. Move to another room | ";
        std::cout << "4. Quit" << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            // Player looks around (no action required)
            std::cout << "You look around the room." << std::endl;
        } else if (choice == 2) {
            // Player interacts with an item in the room
            std::cout << "Enter the name of the item you want to interact with: ";
            std::string itemName;
            std::cin >> itemName;
            for (Item& item : player.GetLocation()->GetItems()) {
                if (item.GetName() == itemName) {
                    item.Interact();
                    // Remove item from room and add to player inventory
                    player.GetLocation()->RemoveItem(item);
                    player.AddItem(item);
                    std::cout << "You picked up the " << item.GetName() << std::endl;
                    break;
                }
            }
        } else if (choice == 3) {
            // Player moves to another room
            std::cout << "Enter the direction (e.g., north, south): ";
            std::string direction;
            std::cin >> direction;
            Room* nextRoom = player.GetLocation()->GetExit(direction);
            if (nextRoom != nullptr) {
                player.SetLocation(nextRoom);
                std::cout << "You move to the next room." << std::endl;
            } else {
                std::cout << "You can't go that way." << std::endl;
            }
        } else if (choice == 4) {
            // Quit the game
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}