#include <iostream>
#include <vector>
#include <map>
#include "Room.h"
#include "Character.h"
#include "Area.h"


int main() {
    Room *room1 = new Room("North room");
    Room *room2 = new Room("South room");

    Item *item1 = new Item("sword", "A sharp sword");
    Item *item2 = new Item("shield", "A sturdy shield");

    room1->AddItem(*item1);
    room2->AddItem(*item2);

    Area *area = new Area();
    area->AddRoom("room1", room1);
    area->AddRoom("room2", room2);

    area->ConnectRooms("room1", "room2", "north");

    // Create a Player
    Player player("Alice", 100);
    // Set the player's starting location
    player.SetLocation(room1);

    // Game loop (basic interaction)
    while (true) {
        std::cout << "Current Location: " << player.GetLocation()->GetDescription() << std::endl;
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