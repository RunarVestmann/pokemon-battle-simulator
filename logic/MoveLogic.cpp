#include <algorithm>
#include <iostream>
#include "MoveLogic.h"
#include "../data/MoveData.h"
#include "PokemonLogic.h"

int MoveLogic::generateID() {
    auto moves = load();
    if (!moves.empty())
        return moves.back()->id + 1;
    return 0;
}

Move *MoveLogic::getMove(int id) {
    return MoveData::getMove(id);
}

vector<Move *> &MoveLogic::load() {
    return MoveData::load();
}

void MoveLogic::save() {
    MoveData::save();
}

void MoveLogic::remove(Move *move) {
    if (move == nullptr) return;
    auto &moves = load();
    auto &allPokemon = PokemonLogic::load();
    int pokemonThatHaveMoveCounter = 0;
    for (auto pokemon : allPokemon)
        for (auto currentMove : pokemon->moves)
            if (currentMove->id == move->id) {
                ++pokemonThatHaveMoveCounter;
                cout << "\n" << pokemon->name << " has the move " << move->name << "\n";
                break;
            }
    if (pokemonThatHaveMoveCounter > 0) {
        cout << "\nCan not delete " << move->name << " since " << pokemonThatHaveMoveCounter
             << " pokemon already " << (pokemonThatHaveMoveCounter == 1 ? "has" : "have") << " that move\n";
        return;
    }

    auto iterator = remove_if(moves.begin(), moves.end(), [move](Move *current){ return current->id == move->id; });
    moves.erase(iterator, moves.end());
    save();
}


