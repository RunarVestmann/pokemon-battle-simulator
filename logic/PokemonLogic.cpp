#include <algorithm>
#include "PokemonLogic.h"
#include "../data/PokemonData.h"

void PokemonLogic::save() {
    PokemonData::save();
}

vector<Pokemon*> &PokemonLogic::load() {
    return PokemonData::load();
}

int PokemonLogic::generateID() {
    auto &pokemonVector = load();
    if (!pokemonVector.empty())
        return pokemonVector.back()->id + 1;
    return 0;
}

void PokemonLogic::remove(Pokemon *pokemon) {
    if (pokemon == nullptr) return;
    auto &allPokemon = load();
    auto iterator = remove_if(allPokemon.begin(), allPokemon.end(), [pokemon](Pokemon *current){ return current->id == pokemon->id; });
    allPokemon.erase(iterator, allPokemon.end());
    save();
}


