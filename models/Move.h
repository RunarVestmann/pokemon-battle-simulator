#ifndef PA5_POKEMON_MOVE_H
#define PA5_POKEMON_MOVE_H

#include "Type.h"

struct Move {
    int id = -1;
    std::string name;
    Type type;
    int powerPoints = 1;
    int attackPower = 1;
    bool isSpecial;
    bool ignoresSpeed;
    int accuracy = 100;

    char *serialize(int &size);
    void deserialize(char *pointer);
    Move *copy();
};

#endif //PA5_POKEMON_MOVE_H
