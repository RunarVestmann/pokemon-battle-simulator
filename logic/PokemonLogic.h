#ifndef PA5_POKEMON_POKEMONLOGIC_H
#define PA5_POKEMON_POKEMONLOGIC_H

#include <vector>
#include "../models/Pokemon.h"
using namespace std;

class PokemonLogic {
public:
    static void save();
    static vector<Pokemon*> & load();
    static void remove(Pokemon *pokemon);


    static int generateID();
};


#endif //PA5_POKEMON_POKEMONLOGIC_H
