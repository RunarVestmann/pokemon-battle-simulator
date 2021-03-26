#ifndef PA5_POKEMON_UIHELPERS_H
#define PA5_POKEMON_UIHELPERS_H

#include "../models/Pokemon.h"
#include <iostream>

static bool containsOnlyDigits(const std::string &s) {
    return s.find_first_not_of("0123456789") == std::string::npos;
}

static bool pokemonAlreadyHasType(Pokemon *pokemon, Type type) {
    for (auto &currentType : pokemon->types)
        if (currentType == type) return true;
    return false;
}

static bool alreadyHasMove(Pokemon *pokemon, Move *move) {
    if (pokemon == nullptr) return false;
    for (int i = 0; i < pokemon->moves.size(); i++)
        if (pokemon->moves[i]->id == move->id) return true;
    return false;

}

static void conditionalPrint(const string& value, bool shouldPrint) {
    if (shouldPrint) std::cout << value;
}

static bool pokemonRanOutOfMoves(Pokemon *pokemon) {
    for (auto move : pokemon->moves) if (move->powerPoints > 0) return false;
    return true;
}

#endif //PA5_POKEMON_UIHELPERS_H
