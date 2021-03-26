#include "BattleUI.h"
#include "PokemonUI.h"
#include "MoveUI.h"
#include "../logic/BattleLogic.h"
#include "UIHelpers.h"

#include <iostream>
#include <string>

using namespace std;

void BattleUI::showOptions() {
    string userInput;
    Pokemon *pokemon1;
    Pokemon *pokemon2;
    while (true) {
        cout << "\n(1) Player vs Player\n(2) Player vs Computer\n(3) Computer vs Computer\n\n(4) Back\n\nSelect an option: ";
        getline(cin, userInput);
        if (userInput == "1") {
            pokemon1 = PokemonUI::pokemonSelectForBattle(1);
            if (pokemon1 == nullptr) continue;
            pokemon2 = PokemonUI::pokemonSelectForBattle(2);
            if (pokemon2 == nullptr) continue;
            battle(pokemon1, pokemon2, false, false);
        }
        else if (userInput == "2")  {
            pokemon1 = PokemonUI::pokemonSelectForBattle(1);
            if (pokemon1 == nullptr) continue;
            pokemon2 = PokemonUI::pokemonSelectForBattle(2);
            if (pokemon2 == nullptr) continue;
            battle(pokemon1, pokemon2, false, true);
        }
        else if (userInput == "3") {
            pokemon1 = PokemonUI::pokemonSelectForBattle(1);
            if (pokemon1 == nullptr) continue;
            pokemon2 = PokemonUI::pokemonSelectForBattle(2);
            if (pokemon2 == nullptr) continue;
            battle(pokemon1, pokemon2, true, true);
        }
        else if (userInput == "4") break;
        else cout << "\nInvalid option selected\n\n";
    }
}

void BattleUI::battle(Pokemon *pokemon1, Pokemon *pokemon2, bool isPokemon1TheComputer, bool isPokemon2TheComputer) {
    auto pokemon1Copy = pokemon1->copy();
    auto pokemon2Copy = pokemon2->copy();

    while (pokemon1Copy->healthPoints > 0 && pokemon2Copy->healthPoints > 0 && !pokemonRanOutOfMoves(pokemon1Copy) && !pokemonRanOutOfMoves(pokemon2Copy)) {
        Move *move1;
        if (isPokemon1TheComputer) {
            cout << "\n" << pokemon1Copy->name << " " << pokemon1Copy->healthPoints << "/" << pokemon1->healthPoints << " vs "
                 << pokemon2Copy->name << " " << pokemon2Copy->healthPoints << "/" << pokemon2->healthPoints << "\n";
            move1 = pokemon1Copy->moves[rand() % pokemon1Copy->moves.size()];
        }
        else {
            cout << "\n" << pokemon1Copy->name << " " << pokemon1Copy->healthPoints << "/" << pokemon1->healthPoints << " vs "
                 << pokemon2Copy->name << " " << pokemon2Copy->healthPoints << "/" << pokemon2->healthPoints << "\n";
            cout << "\nSelect move for " << pokemon1Copy->name << "\n";
            move1 = MoveUI::moveSelectInBattle(pokemon1Copy, pokemon1);
        }

        if (move1 == nullptr) {
            deleteCopies(pokemon1Copy, pokemon2Copy);
            return;
        }

        Move *move2;
        if (isPokemon2TheComputer) {
            move2 = pokemon2Copy->moves[rand() % pokemon2Copy->moves.size()];
        }
        else {
            cout << "\n" << pokemon1Copy->name << " " << pokemon1Copy->healthPoints << "/" << pokemon1->healthPoints << " vs "
                 << pokemon2Copy->name << " " << pokemon2Copy->healthPoints << "/" << pokemon2->healthPoints << "\n";
            cout << "\nSelect move for " << pokemon2Copy->name << "\n";
            move2 = MoveUI::moveSelectInBattle(pokemon2Copy, pokemon2);
        }
        if (move2 == nullptr) {
            deleteCopies(pokemon1Copy, pokemon2Copy);
            return;
        };

        if (pokemon1Copy->speed > pokemon2Copy->speed) {
            if (!move1->ignoresSpeed && move2->ignoresSpeed) {
                BattleLogic::applyMove(move2, pokemon2Copy, pokemon1Copy);
                if (pokemon1Copy->healthPoints <= 0 || pokemon2Copy->healthPoints <= 0) break;
                BattleLogic::applyMove(move1, pokemon1Copy, pokemon2Copy);
            }
            else {
                BattleLogic::applyMove(move1, pokemon1Copy, pokemon2Copy);
                if (pokemon1Copy->healthPoints <= 0 || pokemon2Copy->healthPoints <= 0) break;
                BattleLogic::applyMove(move2, pokemon2Copy, pokemon1Copy);
            }
        }
        else if (pokemon2Copy->speed > pokemon1Copy->speed) {
            if (!move2->ignoresSpeed && move1->ignoresSpeed) {
                BattleLogic::applyMove(move1, pokemon1Copy, pokemon2Copy);
                if (pokemon1Copy->healthPoints <= 0 || pokemon2Copy->healthPoints <= 0) break;
                BattleLogic::applyMove(move2, pokemon2Copy, pokemon1Copy);
            }
            else {
                BattleLogic::applyMove(move2, pokemon2Copy, pokemon1Copy);
                if (pokemon1Copy->healthPoints <= 0 || pokemon2Copy->healthPoints <= 0) break;
                BattleLogic::applyMove(move1, pokemon1Copy, pokemon2Copy);
            }
        }
        else {
            if ((move1->ignoresSpeed && move2->ignoresSpeed) || (!move1->ignoresSpeed && !move2->ignoresSpeed)) {
                int index = rand() % 2;
                if (index == 0) {
                    BattleLogic::applyMove(move1, pokemon1Copy, pokemon2Copy);
                    if (pokemon1Copy->healthPoints <= 0 || pokemon2Copy->healthPoints <= 0) break;
                    BattleLogic::applyMove(move2, pokemon2Copy, pokemon1Copy);
                }
                else {
                    BattleLogic::applyMove(move2, pokemon2Copy, pokemon1Copy);
                    if (pokemon1Copy->healthPoints <= 0 || pokemon2Copy->healthPoints <= 0) break;
                    BattleLogic::applyMove(move1, pokemon1Copy, pokemon2Copy);
                }
            }
            else if (move1->ignoresSpeed && !move2->ignoresSpeed) {
                BattleLogic::applyMove(move1, pokemon1Copy, pokemon2Copy);
                if (pokemon1Copy->healthPoints <= 0 || pokemon2Copy->healthPoints <= 0) break;
                BattleLogic::applyMove(move2, pokemon2Copy, pokemon1Copy);
            }
            else if (!move1->ignoresSpeed && move2->ignoresSpeed) {
                BattleLogic::applyMove(move2, pokemon2Copy, pokemon1Copy);
                if (pokemon1Copy->healthPoints <= 0 || pokemon2Copy->healthPoints <= 0) break;
                BattleLogic::applyMove(move1, pokemon1Copy, pokemon2Copy);
            }
        }
    }

    cout << "\n";
    if (pokemon1Copy->healthPoints <= 0 && pokemon2Copy->healthPoints <= 0)
        cout << "It was a tie" << "\n";
    else if (pokemon1Copy->healthPoints <= 0)
        cout << pokemon2Copy->name << " won the battle!\n";
    else if (pokemon2Copy->healthPoints <= 0)
        cout << pokemon1Copy->name << " won the battle!\n";
    else if (pokemonRanOutOfMoves(pokemon1Copy))
        cout << pokemon1Copy->name << " ran out of moves\n";
    else if (pokemonRanOutOfMoves(pokemon2Copy))
        cout << pokemon2Copy->name << " ran out of moves\n";

    deleteCopies(pokemon1Copy, pokemon2Copy);
}

void BattleUI::deleteCopies(Pokemon *copy1, Pokemon *copy2) {
    for (auto move : copy1->moves) delete move;
    for (auto move : copy2->moves) delete move;
    delete copy1;
    delete copy2;
}
