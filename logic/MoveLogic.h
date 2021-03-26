#ifndef PA5_POKEMON_MOVELOGIC_H
#define PA5_POKEMON_MOVELOGIC_H

#include "../models/Move.h"
using namespace std;

class MoveLogic {
public:
    static int generateID();
    static Move *getMove(int id);
    static vector<Move*> &load();
    static void save();

    static void remove(Move *move);
};


#endif //PA5_POKEMON_MOVELOGIC_H
