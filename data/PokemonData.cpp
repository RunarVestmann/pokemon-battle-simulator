#include "PokemonData.h"
#include "../logic/MoveLogic.h"
#include <fstream>
#include <iostream>

string PokemonData::filename = "allPokemon.bin";
vector<Pokemon*> PokemonData::cache;
bool PokemonData::isCached = false;

vector<Pokemon*> &PokemonData::load() {
    if (isCached) return cache;

    ifstream inputStream;
    inputStream.open(filename, ios::binary);
    if (!inputStream) { isCached = true; return cache; }

    int pokemonCount;
    inputStream.read((char*)&pokemonCount, sizeof(int));

    for (int i = 0; i < pokemonCount; i++) {
        int size;
        inputStream.read((char*)&size, sizeof(int));
        char *loadedData = new char[size];
        inputStream.read(loadedData, size);
        auto *pokemon = new Pokemon();
        pokemon->deserialize(loadedData);
        for (auto &move : pokemon->moves) {
            auto loadedMove = MoveLogic::getMove(move->id);
            delete move;
            move = loadedMove;
        }
        cache.push_back(pokemon);
        delete[] loadedData;
    }
    isCached = true;
    return cache;
}

void PokemonData::save() {
    ofstream outputStream;
    outputStream.open(filename, ios::binary);
    int pokemonCount = cache.size();
    outputStream.write((char*)&pokemonCount, sizeof(int));
    char *serialData;
    for (auto &pokemon : cache) {
        int size;
        serialData = pokemon->serialize(size);
        outputStream.write((char*)&size, sizeof(int));
        outputStream.write(serialData, size);
        delete serialData;
    }
}