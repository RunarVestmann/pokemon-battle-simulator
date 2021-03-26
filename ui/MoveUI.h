#ifndef PA5_POKEMON_MOVEUI_H
#define PA5_POKEMON_MOVEUI_H

#include "../models/Move.h"
#include "../models/Pokemon.h"

using namespace std;

class MoveUI {

public:
    static void showOptions();
    static void showAllMoves(bool onlyNames, bool showCounter);
    static void showCreationMenu();
    static void showEditMenu(Move *move);
    static void showMoveStats(Move *move, bool showCounter=false);
    static Move *moveSelect();
    static Move *moveSelectInBattle(Pokemon* pokemon, Pokemon *originalPokemon);

private:
    static void nameSelect(Move *move);
    static void typeSelect(Move *move);

};


#endif //PA5_POKEMON_MOVEUI_H
