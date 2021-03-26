cmake_minimum_required(VERSION 3.17)
project(pa5_pokemon)

set(CMAKE_CXX_STANDARD 11)

add_executable(pa5_pokemon main.cpp models/Pokemon.h models/Type.h models/Move.h logic/PokemonLogic.cpp logic/PokemonLogic.h ui/MainUI.cpp ui/MainUI.h ui/PokemonUI.cpp ui/PokemonUI.h ui/MoveUI.cpp ui/MoveUI.h ui/UIHelpers.h data/PokemonData.cpp data/PokemonData.h models/Pokemon.cpp models/Move.cpp data/MoveData.cpp data/MoveData.h logic/MoveLogic.cpp logic/MoveLogic.h ui/BattleUI.cpp ui/BattleUI.h logic/BattleLogic.cpp logic/BattleLogic.h)