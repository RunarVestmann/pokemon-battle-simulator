#include "BattleLogic.h"
#include <iostream>
using namespace std;

void BattleLogic::applyMove(Move *move, Pokemon *attacker, Pokemon *defender) {
    cout << "\n" << attacker->name << " used " << move->name << "\n";

    if (rand() % 100 >= move->accuracy) {
        cout << defender->name << " avoided the attack\n";
        return;
    }

    // https://bulbapedia.bulbagarden.net/wiki/Damage
    double level = attacker->level;
    double power = move->attackPower;
    double A = move->isSpecial ? attacker->specialAttack : attacker->attack;
    double D = move->isSpecial ? defender->specialDefense : defender->defense;
    double modifier = calculateTypeModifier(move, defender) * (0.85 + ((double)rand() / RAND_MAX) * (1.0 - 0.85));
    double damage = ((((((2*level) / 5) + 2) * power * A/D) / 50) + 2) * modifier;

    cout << defender->name << "'s health went from " << defender->healthPoints;
    defender->healthPoints -= damage;
    move->powerPoints--;
    cout << " to " << (defender->healthPoints > 0 ? defender->healthPoints : 0) << "\n";
}

double BattleLogic::calculateTypeModifier(Move *move, Pokemon *defender) {
    double modifier = 1.0;
    for (auto type : defender->types) modifier *= typeModifiers[move->type][type];
    if (modifier >= 2.0) cout << "It's super effective!\n";
    if (modifier <= 0.5) cout << "It's not very effective...\n";
    return modifier;
}

