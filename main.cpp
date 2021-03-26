#include "ui/MainUI.h"
#include <random>
#include <chrono>

int main() {
    // Generate and set a random seed
    srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));
    MainUI::showOptions();
    return 0;
}