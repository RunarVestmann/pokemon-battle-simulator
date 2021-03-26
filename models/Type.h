#ifndef PA5_POKEMON_TYPE_H
#define PA5_POKEMON_TYPE_H

#include <string>
#include <vector>

enum Type {
    normal,
    fire,
    water,
    electric,
    grass,
    ice,
    fighting,
    poison,
    ground,
    flying,
    psychic,
    bug,
    rock,
    ghost,
    dragon,
    dark,
    steel,
    fairy
};

static const std::vector<std::string> typeStrings = {
        "Normal",
        "Fire",
        "Water",
        "Electric",
        "Grass",
        "Ice",
        "Fighting",
        "Poison",
        "Ground",
        "Flying",
        "Psychic",
        "Bug",
        "Rock",
        "Ghost",
        "Dragon",
        "Dark",
        "Steel",
        "Fairy"
};

static double typeModifiers[18][18] = {
//                Nor  Fir  Wat  El   Gra  Ice  Fig  Poi  Gro  Fly  Psy  Bug  Rock Ghost Drag Dark Ste  Fairy
    /*Normal*/   {1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0.5, 0,    1,   1,   0.5, 1},
    /*Fire*/     {1,   0.5, 0.5, 1,   2,   2,   1,   1,   1,   1,   1,   2,   0.5, 1,   0.5, 1,   2,   1},
    /*Water*/    {1,   2,   0.5, 1,   0.5, 1,   1,   1,   2,   1,   1,   1,   2,   1,   0.5, 1,   1,   1},
    /*Electric*/ {1,   1,   2,   0.5, 0.5, 1,   1,   1,   0,   2,   1,   1,   1,   1,   0.5, 1,   1,   1},
    /*Grass*/    {1,   0.5, 2,   1,   0.5, 1,   1,   0.5, 2,   0.5, 1,   0.5, 2,   1,   0.5, 1,   0.5, 1},
    /*Ice*/      {1,   0.5, 0.5, 1,   2,   0.5, 1,   1,   2,   2,   1,   1,   1,   1,   2,   1,   0.5, 1},
    /*Fighting*/ {2,   1,   1,   1,   1,   2,   1,   0.5, 1,   0.5, 0.5, 0.5, 2,   0,   1,   2,   2,   0.5},
    /*Poison*/   {1,   1,   1,   1,   2,   1,   1,   0.5, 0.5, 1,   1,   1,   0.5, 0.5, 1,   1,   0,   2},
    /*Ground*/   {1,   2,   1,   2,   0.5, 1,   1,   2,   1,   0,   1,   0.5, 2,   1,   1,   1,   2,   1},
    /*Flying*/   {1,   1,   1,   0.5, 2,   1,   2,   1,   1,   1,   1,   2,   0.5, 1,   1,   1,   0.5, 1},
    /*Psychic*/  {1,   1,   1,   1,   1,   1,   2,   2,   1,   1,   0.5, 1,   1,   1,   1,   0,   0.5, 1},
    /*Bug*/      {1,   0.5, 1,   1,   2,   1,   0.5, 0.5, 1,   0.5, 2,   1,   1,   0.5, 1,   2,   0.5, 0.5},
    /*Rock*/     {1,   2,   1,   1,   1,   2,   0.5, 1,   0.5, 2,   1,   2,   1,   1,   1,   1,   0.5, 1},
    /*Ghost*/    {0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0.5, 1,   1,   2,   1,   0.5, 1,   1},
    /*Dragon*/   {1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1,   0.5, 0},
    /*Dark*/     {1,   1,   1,   1,   1,   1,   0.5, 1,   1,   1,   2,   1,   1,   2,   1,   0.5, 1,   0.5},
    /*Steel*/    {1,   0.5, 0.5, 0.5, 1,   2,   1,   1,   1,   1,   1,   2,   0.5, 1,   1,   1,   0.5, 2},
    /*Fairy*/    {1,   0.5, 1,   1,   1,   1,   2,   0.5, 1,   1,   1,   1,   1,   1,   2,   2,   0.5, 1},
};

#endif //PA5_POKEMON_TYPE_H
