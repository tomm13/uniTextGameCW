#ifndef SPRINGCOURSEWORK_COMMANDINTERPRETER_H
#define SPRINGCOURSEWORK_COMMANDINTERPRETER_H


#include <string>
#include "Character.h"

class CommandInterpreter {
public:
    explicit CommandInterpreter(Player* player) : player_(player) {}
    void interpretCommand(const std::string &command);
    Player GetPlayer();

private:
    Player* player_;
};

#endif //SPRINGCOURSEWORK_COMMANDINTERPRETER_H
