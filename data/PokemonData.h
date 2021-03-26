#ifndef PA5_POKEMON_POKEMONDATA_H
#define PA5_POKEMON_POKEMONDATA_H

#include <string>
#include <vector>
#include "../models/Pokemon.h"
using namespace std;

class PokemonData {
public:
    static vector<Pokemon*> &load();
    static void save();

private:
    static string filename;
    static vector<Pokemon*> cache;
    static bool isCached;
};

#endif //PA5_POKEMON_POKEMONDATA_H
