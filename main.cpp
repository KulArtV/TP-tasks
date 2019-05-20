#include <iostream>
#include "game.h"

int main() {
    Game game;
    SovietArmyFactory s_factory;
    Army* soviet_army = game.create_army(s_factory);
    GermanArmyFactory g_factory;
    Army* german_army = game.create_army(g_factory);
    std::cout << "Armies are created" << '\n';
    Subdivision* whole_soviet_army = new Subdivision(soviet_army);
    Subdivision* whole_german_army = new Subdivision(german_army);
    return 0;
}
