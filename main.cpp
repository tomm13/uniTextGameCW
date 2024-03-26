#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Room.h"
#include "Character.h"
#include "Area.h"
#include "CommandInterpreter.h"


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

    CommandInterpreter interpreter(&player);

    // Game loop (basic interaction)
    while (true) {
        std::cout << "Current Location: " << player.GetLocation()->GetDescription() << std::endl;
        std::cout << "In your inventory:" << std::endl;
        for (const Item& item : player.GetInventory()) {
            std::cout << "- " << item.GetName() << ": " <<
                      item.GetDescription() << std::endl;
        }
        std::cout << "Items in the room:" << std::endl;
        for (const Item& item : player.GetLocation()->GetItems()) {
            std::cout << "- " << item.GetName() << ": " <<
                      item.GetDescription() << std::endl;
        }
        std::cout << "Options | Enter commands in lowercase" << std::endl;
        std::cout << "LOOK around, ";
        std::cout << "INTERACT with an item, ";
        std::cout << "MOVE to another room, ";
        std::cout << "QUIT" << std::endl;
        std::string command;
        std::cin >> command;

        interpreter.interpretCommand(command);
    }

    return 0;
}