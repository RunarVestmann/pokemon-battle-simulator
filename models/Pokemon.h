#ifndef PA5_POKEMON_POKEMON_H
#define PA5_POKEMON_POKEMON_H

#include "Type.h"
#include "Move.h"
#include <vector>
#include <string>

struct Pokemon {
    int id = -1;
    std::string name;
    std::vector<Type> types;
    std::vector<Move*> moves;
    int healthPoints = 1;
    int level = 1;
    int attack = 1;
    int defense = 1;
    int specialAttack = 1;
    int specialDefense = 1;
    int speed = 1;

    char *serialize(int &size);
    void deserialize(char *pointer);
    Pokemon *copy();
};

#endif //PA5_POKEMON_POKEMON_H
