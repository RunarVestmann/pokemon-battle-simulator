#include <cstring>
#include "Move.h"

char *Move::serialize(int &size) {
    char *pointer;
    char *startingPoint;
    int nameLength = name.length();
    //        id        name length     name            type,pp,atk   isSpecial,ignoresSpd   accuracy
    size = sizeof(int) + sizeof(int) + nameLength +   3 * sizeof(int) + 2 * sizeof(bool) + sizeof(int);
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

    // type
    memcpy(pointer, &type, sizeof(int));
    pointer += sizeof(int);

    // pp
    memcpy(pointer, &powerPoints, sizeof(int));
    pointer += sizeof(int);

    // atk
    memcpy(pointer, &attackPower, sizeof(int));
    pointer += sizeof(int);

    //isSpecial
    memcpy(pointer, &isSpecial, sizeof(bool));
    pointer += sizeof(bool);

    // ignoresSpd
    memcpy(pointer, &ignoresSpeed, sizeof(bool));
    pointer += sizeof(bool);

    // accuracy
    memcpy(pointer, &accuracy, sizeof(int));

    return startingPoint;
}

void Move::deserialize(char *pointer) {
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

    // type
    memcpy(&type, pointer, sizeof(int));
    pointer += sizeof(int);

    // pp
    memcpy(&powerPoints, pointer, sizeof(int));
    pointer += sizeof(int);

    // atk
    memcpy(&attackPower, pointer, sizeof(int));
    pointer += sizeof(int);

    //isSpecial
    memcpy(&isSpecial, pointer, sizeof(bool));
    pointer += sizeof(bool);

    // ignoresSpd
    memcpy(&ignoresSpeed, pointer, sizeof(bool));
    pointer += sizeof(bool);

    // accuracy
    memcpy(&accuracy, pointer, sizeof(int));
}

Move *Move::copy() {
    auto move = new Move();

    move->id = id;
    move->name = name.c_str();
    move->type = type;
    move->powerPoints = powerPoints;
    move->attackPower = attackPower;
    move->isSpecial = isSpecial;
    move->ignoresSpeed = ignoresSpeed;
    move->accuracy = accuracy;

    return move;
}

