#ifndef PA5_POKEMON_BATTLELOGIC_H
#define PA5_POKEMON_BATTLELOGIC_H


#include "../models/Move.h"
#include "../models/Pokemon.h"

class BattleLogic {
public:
    static void applyMove(Move *move, Pokemon *attacker, Pokemon *defender);
    static double calculateTypeModifier(Move *move, Pokemon *defender);
private:
};


#endif //PA5_POKEMON_BATTLELOGIC_H
