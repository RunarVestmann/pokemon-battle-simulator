#ifndef PA5_POKEMON_BATTLEUI_H
#define PA5_POKEMON_BATTLEUI_H


#include "../models/Pokemon.h"

class BattleUI {
public:
    static void showOptions();
    static void battle(Pokemon *pokemon1, Pokemon* pokemon2, bool isPokemon1TheComputer, bool isPokemon2TheComputer);
private:
    static void deleteCopies(Pokemon *copy1, Pokemon *copy2);
};


#endif //PA5_POKEMON_BATTLEUI_H
