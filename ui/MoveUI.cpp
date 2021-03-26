#include <iostream>
#include "MoveUI.h"
#include "UIHelpers.h"
#include "../logic/MoveLogic.h"

void MoveUI::showOptions() {
    string userInput;
    while (true) {
        cout << "\n(1) Show All Moves\n(2) Create Move\n(3) Edit Move\n(4) Delete Move\n\n(5) Back\n\nSelect an option: ";
        getline(cin, userInput);
        if (userInput == "1") {
            cout << "\n(1) All stats\n(2) Only names\n\n(3) Back\n\nSelect an option: ";
            getline(cin, userInput);
            if (userInput == "1") showAllMoves(false, false);
            else if (userInput == "2") showAllMoves(true, false);
            else if (userInput == "3") continue;
            else cout << "\nInvalid option selected\n";
        }
        else if (userInput == "2") showCreationMenu();
        else if (userInput == "3") {
            Move *move = moveSelect();
            if (move != nullptr) showEditMenu(move);
        }
        else if (userInput == "4") {
            auto move = moveSelect();
            MoveLogic::remove(move);
        }
        else if (userInput == "5") { cout << "\n"; break; }
        else cout << "\nInvalid option selected\n\n";
    }
}

void MoveUI::showAllMoves(bool onlyNames, bool showCounter) {
    auto &moves = MoveLogic::load();
    cout << "\n";
    if (moves.empty()) { cout << "No moves found" << "\n"; return;}
    int counter = 1;

    for (int i = 0; i < moves.size(); i++) {
        if (onlyNames) {
            conditionalPrint("(" + to_string(counter++) + ") ", showCounter);
            cout << moves[i]->name << "\n";
        }
        else {
            showMoveStats(moves[i], false);
            if (i < moves.size()-1) cout << "\n";
        }
    }
}

void MoveUI::showCreationMenu() {
    auto move = new Move();
    nameSelect(move);
    typeSelect(move);
    showEditMenu(move);
}

void MoveUI::nameSelect(Move *move) {
    string userInput;
    cout << "\nEnter name: ";
    getline(cin, userInput);
    move->name = userInput;
    cout << "\n";
}

void MoveUI::typeSelect(Move *move) {
    string userInput;

    while (true) {
        for (int i = 0; i < typeStrings.size(); i++)
            cout << "(" << (i+1) << ") " << typeStrings[i] << "\n";
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
        cout << "\n";
        move->type = (Type)(option-1);
        break;
    }
}

void MoveUI::showEditMenu(Move *move) {
    while (true) {
        showMoveStats(move, true);
        cout << "\n(8) Back    (9) Submit\n\n";
        string userInput;
        cout << "Select an option: ";
        getline(cin, userInput);

        if (userInput == "8") { delete move; break; };
        if (userInput == "9") {
            auto &moves = MoveLogic::load();
            if (move->id == -1) {
                move->id = MoveLogic::generateID();
                moves.push_back(move);
            }
            MoveLogic::save();
            break;
        }
        if (userInput == "1") nameSelect(move);
        else if (userInput == "2") typeSelect(move);
        else if (userInput == "3") {
            cout << "\nEnter power points: ";
            getline(cin, userInput);
            cout << "\n";

            if (userInput.empty()) continue;
            if (!containsOnlyDigits(userInput)) { cout << "Power points can only be an integer\n\n"; continue;}

            int option = stoi(userInput);
            if (option < 1) { cout << "Power points can not be at 0 or below\n\n"; continue;}
            move->powerPoints = option;
        }
        else if (userInput == "4") {
            cout << "\nEnter attack power: ";
            getline(cin, userInput);
            cout << "\n";

            if (userInput.empty()) continue;
            if (!containsOnlyDigits(userInput)) { cout << "Attack power can only be an integer\n\n"; continue;}

            int option = stoi(userInput);
            if (option < 1) { cout << "Attack power can not be at 0 or below\n\n"; continue;}
            move->attackPower = option;
        }
        else if (userInput == "5") {
            cout << "Is this a special move? (y/n) ";
            getline(cin, userInput);
            cout << "\n";
            move->isSpecial = userInput.rfind('y', 0) == 0;
        }
        else if (userInput == "6") {
            cout << "Does this move ignore speed? (y/n) ";
            getline(cin, userInput);
            cout << "\n";
            move->ignoresSpeed = userInput.rfind('y', 0) == 0;
        }
        else if (userInput == "7") {
            cout << "\nEnter accuracy: ";
            getline(cin, userInput);
            cout << "\n";

            if (userInput.empty()) continue;
            if (!containsOnlyDigits(userInput)) { cout << "Accuracy can only be an integer\n\n"; continue;}

            int option = stoi(userInput);
            if (option < 1) { cout << "Accuracy can not be at 0 or below\n\n"; continue;}
            move->accuracy = option;
        }
    }
}

void MoveUI::showMoveStats(Move *move, bool showCounter) {
    int counter = 1;

    // Name
    conditionalPrint("(" + to_string(counter++) + ") ", showCounter);
    cout << "Name: " << move->name << "\n";

    // Type
    conditionalPrint("(" + to_string(counter++) + ") ", showCounter);
    cout << "Type: " << typeStrings[move->type] << "\n";

    // Power Points
    conditionalPrint("(" + to_string(counter++) + ") ", showCounter);
    cout << "Power Points: " << move->powerPoints << "\n";

    // Attack Power
    conditionalPrint("(" + to_string(counter++) + ") ", showCounter);
    cout << "Attack Power: " << move->attackPower << "\n";

    // Category
    conditionalPrint("(" + to_string(counter++) + ") ", showCounter);
    cout << "Category: " << (move->isSpecial ? "Special" : "Physical") << "\n";

    // Ignores Speed
    conditionalPrint("(" + to_string(counter++) + ") ", showCounter);
    cout << (move->ignoresSpeed ? "Ignores Speed" : "Does Not Ignore Speed") << "\n";

    // Accuracy
    conditionalPrint("(" + to_string(counter++) + ") ", showCounter);
    cout << "Accuracy: " << move->accuracy << "\n";
}

Move *MoveUI::moveSelect() {
    auto &moves = MoveLogic::load();
    string userInput;
    int back = moves.size() + 1;
    while (true) {
        showAllMoves(true, true);
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
        return moves[option-1];
    }
}

Move *MoveUI::moveSelectInBattle(Pokemon *pokemonCopy, Pokemon *originalPokemon) {
    int back = pokemonCopy->moves.size() + 1;
    string userInput;
    while (true) {
        for (int i = 0; i < pokemonCopy->moves.size(); i++) {
            auto move = pokemonCopy->moves[i];
            cout << "\n(" << i+1 << ") " << move->name << " (" << typeStrings[move->type] << ") "
                 << move->powerPoints << "/" << originalPokemon->moves[i]->powerPoints << "\n";
            cout << (move->isSpecial ? "Special" : "Physical") << " ATK: " << move->attackPower << " Accuracy: " << move->accuracy << "\n";
        }
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
        return pokemonCopy->moves[option-1];
    }

}


