#include "PokemonUI.h"
#include "UIHelpers.h"
#include "../logic/PokemonLogic.h"
#include "MoveUI.h"
#include <iostream>
#include <algorithm>

using namespace std;

void PokemonUI::showOptions() {
    string userInput;
    Pokemon *pokemon;
    while (true) {
        cout << "\n(1) Show All Pokemon\n(2) Create Pokemon\n(3) Edit Pokemon\n(4) Delete Pokemon\n\n(5) Back\n\nSelect an option: ";
        getline(cin, userInput);
        if (userInput == "1") {
            cout << "\n(1) All stats\n(2) Only names\n\n(3) Back\n\nSelect an option: ";
            getline(cin, userInput);
            if (userInput == "1") showAllPokemon(false, false);
            else if (userInput == "2") showAllPokemon(true, false);
            else if (userInput == "3") continue;
            else cout << "\nInvalid option selected\n";
        }
        else if (userInput == "2") showCreationMenu();
        else if (userInput == "3") {
            pokemon = pokemonSelect();
            if (pokemon != nullptr) showEditMenu(pokemon);
        }
        else if (userInput == "4") {
            pokemon = pokemonSelect();
            PokemonLogic::remove(pokemon);
        }
        else if (userInput == "5") { cout << "\n"; break; }
        else cout << "\nInvalid option selected\n\n";
    }
}

void PokemonUI::showCreationMenu() {
    auto pokemon = new Pokemon();
    nameSelect(pokemon);
    typeSelect(pokemon);
    showEditMenu(pokemon);
}

void PokemonUI::nameSelect(Pokemon *pokemon) {
    string userInput;
    cout << "\nEnter name: ";
    getline(cin, userInput);
    pokemon->name = userInput;
    cout << "\n";
}

void PokemonUI::typeSelect(Pokemon *pokemon) {
    string userInput;

    while (true) {
        for (int i = 0; i < typeStrings.size(); i++) {
            cout << "(" << (i+1) << ") " << typeStrings[i] << "\n";
        }
        cout << "\nSelect a type: ";
        getline(cin, userInput);

        if (userInput.empty() || !containsOnlyDigits(userInput)) {
            cout << "\nInvalid option selected\n\n";
            continue;
        }
        int option = stoi(userInput);
        if (option < 1 || option > typeStrings.size()) {
            cout << "\nInvalid option selected\n\n";
            continue;
        }
        auto type = (Type)(option-1);
        if (pokemonAlreadyHasType(pokemon, type)) {
            auto iterator = remove_if(pokemon->types.begin(), pokemon->types.end(), [type](Type current){ return current == type; });
            pokemon->types.erase(iterator, pokemon->types.end());
            if (pokemon->types.empty()) pokemon->types.push_back(normal);
        }
        else pokemon->types.push_back((Type)(option-1));
        if (pokemon->types.size() == typeStrings.size()) break;

        cout << "\nWant to add another type? (y/n): ";
        getline(cin, userInput);
        if (userInput.rfind('y', 0) != 0) { cout << "\n"; break; }
    }
}

Pokemon *PokemonUI::pokemonSelect() {
    auto &pokemonVector = PokemonLogic::load();
    string userInput;
    int back = pokemonVector.size() + 1;
    while (true) {
        showAllPokemon(true, true);
        cout << "\n(" << back << ") Back\n\n";
        cout << "Select an option: ";
        getline(cin, userInput);

        if (userInput.empty() || !containsOnlyDigits(userInput)) {
            cout << "\nInvalid option selected\n\n";
            continue;
        }
        int option = stoi(userInput);
        if (option < 0 || option > back) {
            cout << "\nInvalid option selected\n\n";
            continue;
        }
        if (option == back) return nullptr;
        return pokemonVector[option-1];
    }

}

void PokemonUI::showEditMenu(Pokemon *pokemon) {
    while (true) {
        showPokemonStats(pokemon, true);
        cout << "\n(11) Back    (12) Submit\n\n";
        string userInput;
        cout << "Select an option: ";
        getline(cin, userInput);

        if (userInput == "11") { delete pokemon; break; };
        if (userInput == "12") {
            if (pokemon->id == -1) {
                pokemon->id = PokemonLogic::generateID();
                auto &pokemonVector = PokemonLogic::load();
                pokemonVector.push_back(pokemon);
            }
            PokemonLogic::save();
            break;
        }
        if (userInput == "1") nameSelect(pokemon);
        else if (userInput == "2") typeSelect(pokemon);
        else if (userInput == "3") moveSelect(pokemon);
        else if (userInput == "4") {
            cout << "\nEnter health points: ";
            getline(cin, userInput);
            cout << "\n";

            if (userInput.empty()) continue;
            if (!containsOnlyDigits(userInput)) { cout << "Health points can only be an integer\n\n"; continue;}

            int option = stoi(userInput);
            if (option < 1) { cout << "Health points can not be at 0 or below\n\n"; continue;}
            pokemon->healthPoints = option;
        }
        else if (userInput == "5") {
            cout << "\nEnter level: ";
            getline(cin, userInput);
            cout << "\n";

            if (userInput.empty()) continue;
            if (!containsOnlyDigits(userInput)) { cout << "Level can only be an integer\n\n"; continue;}

            int option = stoi(userInput);
            if (option < 1 || option > 100) { cout << "Level can only be from 1 to 100(inclusive)\n\n"; continue;}
            pokemon->level = option;
        }
        else if (userInput == "6") {
            cout << "\nEnter attack: ";
            getline(cin, userInput);
            cout << "\n";

            if (userInput.empty()) continue;
            if (!containsOnlyDigits(userInput)) { cout << "Attack can only be an integer\n\n"; continue;}

            int option = stoi(userInput);
            if (option < 1) { cout << "Attack can not be at 0 or below\n\n"; continue;}
            pokemon->attack = option;
        }
        else if (userInput == "7") {
            cout << "\nEnter defense: ";
            getline(cin, userInput);
            cout << "\n";

            if (userInput.empty()) continue;
            if (!containsOnlyDigits(userInput)) { cout << "Defense can only be an integer\n\n"; continue;}

            int option = stoi(userInput);
            if (option < 1) { cout << "Defense can not be at 0 or below\n\n"; continue;}
            pokemon->defense = option;
        }
        else if (userInput == "8") {
            cout << "\nEnter special attack: ";
            getline(cin, userInput);
            cout << "\n";

            if (userInput.empty()) continue;
            if (!containsOnlyDigits(userInput)) { cout << "Special Attack can only be an integer\n\n"; continue;}

            int option = stoi(userInput);
            if (option < 1) { cout << "Special Attack can not be at 0 or below\n\n"; continue;}
            pokemon->specialAttack = option;
        }
        else if (userInput == "9") {
            cout << "\nEnter special defense: ";
            getline(cin, userInput);
            cout << "\n";

            if (userInput.empty()) continue;
            if (!containsOnlyDigits(userInput)) { cout << "Special Defense can only be an integer\n\n"; continue;}

            int option = stoi(userInput);
            if (option < 1) { cout << "Special Defense can not be at 0 or below\n\n"; continue;}
            pokemon->specialDefense = option;
        }
        else if (userInput == "10") {
            cout << "\nEnter speed: ";
            getline(cin, userInput);
            cout << "\n";

            if (userInput.empty()) continue;
            if (!containsOnlyDigits(userInput)) { cout << "Speed can only be an integer\n\n"; continue;}

            int option = stoi(userInput);
            if (option < 1) { cout << "Speed can not be at 0 or below\n\n"; continue;}
            pokemon->speed = option;
        }
        else {
            cout << "\n";
        }
    }
}

void PokemonUI::showPokemonStats(Pokemon *pokemon, bool counterDisplay) {
    int counter = 1;

    // Name
    conditionalPrint("(" + to_string(counter++) + ") ", counterDisplay);
    cout << "Name: " << pokemon->name << "\n";

    // Type
    conditionalPrint("(" + to_string(counter++) + ") ", counterDisplay);
    cout << "Type:";
    for (int i = 0; i < pokemon->types.size(); i++) {
        if (i == 0) cout << " ";
        else cout <<  ", ";
        cout << typeStrings[pokemon->types[i]];
    }
    cout << "\n";

    // Moves
    conditionalPrint("(" + to_string(counter++) + ") ", counterDisplay);
    cout << "Moves:";
    for (int i = 0; i < pokemon->moves.size(); i++) {
        if (i == 0) cout << " ";
        else cout <<  ", ";
        cout << pokemon->moves[i]->name;
    }
    cout << "\n";

    // Health points
    conditionalPrint("(" + to_string(counter++) + ") ", counterDisplay);
    cout << "Health Points: " << pokemon->healthPoints << "\n";

    // Level
    conditionalPrint("(" + to_string(counter++) + ") ", counterDisplay);
    cout << "Level: " << pokemon->level << "\n";

    // Attack
    conditionalPrint("(" + to_string(counter++) + ") ", counterDisplay);
    cout << "Attack: " << pokemon->attack << "\n";

    conditionalPrint("(" + to_string(counter++) + ") ", counterDisplay);
    cout << "Defense: " << pokemon->defense << "\n";

    // Special Attack
    conditionalPrint("(" + to_string(counter++) + ") ", counterDisplay);
    cout << "Special Attack: " << pokemon->specialAttack << "\n";

    // Special Attack
    conditionalPrint("(" + to_string(counter++) + ") ", counterDisplay);
    cout << "Special Defense: " << pokemon->specialDefense << "\n";

    // Speed
    conditionalPrint("(" + to_string(counter++) + ") ", counterDisplay);
    cout << "Speed: " << pokemon->speed << "\n";
}

void PokemonUI::showAllPokemon(bool onlyNames, bool showCounter) {
    auto &pokemonVector = PokemonLogic::load();
    cout << "\n";

    if (pokemonVector.empty()) { cout << "No pokemon found" << "\n"; return;}

    int counter = 1;
    for (int i = 0; i < pokemonVector.size(); i++) {
        if (onlyNames) {
            conditionalPrint("(" + to_string(counter++) + ") ", showCounter);
            cout << pokemonVector[i]->name << "\n";
        }
        else {
            showPokemonStats(pokemonVector[i], showCounter);
            if (i < pokemonVector.size()-1) cout << "\n";
        }
    }
}

void PokemonUI::moveSelect(Pokemon *pokemon) {
    auto move = MoveUI::moveSelect();
    if (move == nullptr) return;
    if (alreadyHasMove(pokemon, move)) {
        auto iterator = remove_if(pokemon->moves.begin(), pokemon->moves.end(), [move](Move *current){ return current->id == move->id; });
        pokemon->moves.erase(iterator, pokemon->moves.end());
    }
    else pokemon->moves.push_back(move);
    cout << "\n";
}

Pokemon *PokemonUI::pokemonSelectForBattle(int counter) {
    auto &pokemonVector = PokemonLogic::load();
    string userInput;
    int back = pokemonVector.size() + 1;
    while (true) {
        showAllPokemon(true, true);
        cout << "\n(" << back << ") Back\n\n";
        cout << "Select pokemon " << counter << ": ";
        getline(cin, userInput);

        if (userInput.empty() || !containsOnlyDigits(userInput)) {
            cout << "\nInvalid option selected\n\n";
            continue;
        }
        int option = stoi(userInput);
        if (option < 0 || option > back) {
            cout << "\nInvalid option selected\n\n";
            continue;
        }
        if (option == back) return nullptr;
        return pokemonVector[option-1];
    }
}

