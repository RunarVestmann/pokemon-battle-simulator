#ifndef PA5_POKEMON_POKEMONUI_H
#define PA5_POKEMON_POKEMONUI_H

#include "../models/Pokemon.h"
using namespace std;

class PokemonUI {

public:
    static void showOptions();
    static void showCreationMenu();
    static Pokemon *pokemonSelect();
    static Pokemon *pokemonSelectForBattle(int counter);

private:
    static void nameSelect(Pokemon *pokemon);
    static void typeSelect(Pokemon *pokemon);


    static void showEditMenu(Pokemon *pokemon);
    static void showPokemonStats(Pokemon *pokemon, bool counterDisplay=false);
    static void showAllPokemon(bool onlyNames, bool showCounter);

    static void moveSelect(Pokemon *pokemon);
};


#endif //PA5_POKEMON_POKEMONUI_H
