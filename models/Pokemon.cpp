#include <cstring>
#include "Pokemon.h"

char *Pokemon::serialize(int &size) {
    char *pointer;
    char *startingPoint;
    int nameLength = name.size();
    int typeCount = types.size();
    int moveCount = moves.size();
    //        id         name length      name        type count               types        move count           moves                  rest
    size = sizeof(int) + sizeof(int) + nameLength + sizeof(int) + typeCount * sizeof(int) + sizeof(int) + moveCount * sizeof(int) +   7 * sizeof(int);
    pointer = new char[size];
    startingPoint = pointer;

    // id
    memcpy(pointer, &id, sizeof(int));
    pointer += sizeof(int);

    // name length
    memcpy(pointer, &nameLength, sizeof(int));
    pointer += sizeof(int);

    // name
    memcpy(pointer, name.c_str(), nameLength);
    pointer += nameLength;

    // type count
    memcpy(pointer, &typeCount, sizeof(int));
    pointer += sizeof(int);

    // types
    for (auto type : types) {
        memcpy(pointer, &type, sizeof(int));
        pointer += sizeof(int);
    }

    // move count
    memcpy(pointer, &moveCount, sizeof(int));
    pointer += sizeof(int);

    // moves
    for (auto &move : moves) {
        memcpy(pointer, &move->id, sizeof(int));
        pointer += sizeof(int);
    }

    // rest

    // health points
    memcpy(pointer, &healthPoints, sizeof(int));
    pointer += sizeof(int);

    // level
    memcpy(pointer, &level, sizeof(int));
    pointer += sizeof(int);

    // attack
    memcpy(pointer, &attack, sizeof(int));
    pointer += sizeof(int);

    // defense
    memcpy(pointer, &defense, sizeof(int));
    pointer += sizeof(int);

    // specialAttack
    memcpy(pointer, &specialAttack, sizeof(int));
    pointer += sizeof(int);

    // specialDefense
    memcpy(pointer, &specialDefense, sizeof(int));
    pointer += sizeof(int);

    // speed
    memcpy(pointer, &speed, sizeof(int));

    return startingPoint;
}

void Pokemon::deserialize(char *pointer) {
    // id
    memcpy(&id, pointer, sizeof(int));
    pointer += sizeof(int);

    // name length
    int nameLength;
    memcpy(&nameLength, pointer, sizeof(int));
    pointer += sizeof(int);

    // name
    char loadedName[nameLength+1];
    memcpy(loadedName, pointer, nameLength);
    pointer += nameLength;
    loadedName[nameLength] = '\0';
    name = loadedName;

    // type count
    int typeCount;
    memcpy(&typeCount, pointer, sizeof(int));
    pointer += sizeof(int);

    // types
    for (int i = 0; i < typeCount; i++) {
        Type loadedType;
        memcpy(&loadedType, pointer, sizeof(int));
        types.push_back(loadedType);
        pointer += sizeof(int);
    }

    // move count
    int moveCount;
    memcpy(&moveCount, pointer, sizeof(int));
    pointer += sizeof(int);

    // moves
    for (int i = 0; i < moveCount; i++) {
        Move *move = new Move();
        memcpy(&move->id, pointer , sizeof(int));
        moves.push_back(move);
        pointer += sizeof(int);
    }

    // health points
    memcpy(&healthPoints, pointer, sizeof(int));
    pointer += sizeof(int);

    // level
    memcpy(&level, pointer, sizeof(int));
    pointer += sizeof(int);

    // attack
    memcpy(&attack, pointer, sizeof(int));
    pointer += sizeof(int);

    // defense
    memcpy(&defense, pointer, sizeof(int));
    pointer += sizeof(int);

    // specialAttack
    memcpy(&specialAttack, pointer, sizeof(int));
    pointer += sizeof(int);

    // specialDefense
    memcpy(&specialDefense, pointer, sizeof(int));
    pointer += sizeof(int);

    // speed
    memcpy(&speed, pointer, sizeof(int));
}

Pokemon *Pokemon::copy() {
    auto pokemon = new Pokemon();
    pokemon->id = id;
    pokemon->name = name;
    pokemon->types = types;
    for (auto move : moves) pokemon->moves.push_back(move->copy());
    pokemon->healthPoints = healthPoints;
    pokemon->level = level;
    pokemon->attack = attack;
    pokemon->defense = defense;
    pokemon->specialAttack = specialAttack;
    pokemon->specialDefense = specialDefense;
    pokemon->speed = speed;

    return pokemon;
}

