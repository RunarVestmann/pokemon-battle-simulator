#include "MainUI.h"
#include "BattleUI.h"
#include "PokemonUI.h"
#include "MoveUI.h"

void MainUI::showOptions() {
    string userInput;
    while (true) {
        cout << "(1) Battle Menu\n(2) Pokemon Menu\n(3) Move Menu\n\n(4) Quit\n\nSelect an option: ";
        getline(cin, userInput);
        if (userInput == "1") BattleUI::showOptions();
        else if (userInput == "2") PokemonUI::showOptions();
        else if (userInput == "3") MoveUI::showOptions();
        else if (userInput == "4") break;
        else cout << "\nInvalid option selected\n\n";
    }
}