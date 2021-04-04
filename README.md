A simple C++ terminal application that simulates Pokémon battles.

Game modes:
Player vs Player
Player vs Computer
Computer vs Computer

A command that creates an executable:
g++ -o main main.cpp ui/*.cpp logic/*.cpp data/*.cpp models/*.cpp -std=c++11

After you've created that executable (which is called main) you run that file to see the program in action.

The following website provides the method used during damage calculation:
https://bulbapedia.bulbagarden.net/wiki/Damage

The following website was used as a reference to give created Pokémon correct stats with 252 252 6 EVs distributed accordingly:
http://www.psypokes.com/dex/stats.php

**Screenshots**

```bash
Main Menu
```
![Main menu](screenshots/main-menu.PNG)
```bash
Battle Menu
```
![Battle menu](screenshots/battle-menu.PNG)
```bash
Player vs Computer Battle
```
![Player vs Computer Battle](screenshots/player-vs-pc.PNG)
```bash
Computer vs Computer Battle
```
![Computer vs Computer Battle](screenshots/pc-vs-pc.PNG)
```bash
Pokémon Menu
```
![Pokémon menu](screenshots/pokemon-menu.PNG)
```bash
Show All Pokémon
```
![All Pokémon](screenshots/pokemon-stats.PNG)
```bash
Move Menu
```
![Move menu](screenshots/move-menu.PNG)
```bash
Show All Moves
```
![All Moves](screenshots/move-stats.PNG)