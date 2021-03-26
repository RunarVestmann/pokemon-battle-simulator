#ifndef PA5_POKEMON_MOVEDATA_H
#define PA5_POKEMON_MOVEDATA_H

#include <string>
#include "../models/Move.h"
using namespace std;

class MoveData {
public:
    static vector<Move*>& load();
    static void save();
    static Move *getMove(int id);

private:
    static string filename;
    static vector<Move*> cache;
    static bool isCached;
};


#endif //PA5_POKEMON_MOVEDATA_H
