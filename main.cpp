#include <iostream>
#include <string>
#include "game.h"

int main() {
    Game game;
    SovietArmyFactory s_factory;
    Army* soviet_army = game.create_army(s_factory);
    GermanArmyFactory g_factory;
    Army* german_army = game.create_army(g_factory);
    std::cout << "Armies are created\n";
    auto soviet_division = new Subdivision(soviet_army);
    auto german_division = new Subdivision(german_army);
    soviet_division->divide();
    german_division->divide();
    std::cout << "Armies are divided and ready to battle\n";
    auto global_observer = new Observer();
    vector<Unit*> all_soviet = soviet_division->get_all_units();
    vector<Unit*> all_german = german_division->get_all_units();

    for (auto unit: all_soviet) {
        global_observer->add_unit(unit, SOVIET);
    }
    for (auto unit: all_german) {
        global_observer->add_unit(unit, GERMANY);
    }
    global_observer->recalc_distances();
    while (true) {
        std::string command;
        std::cin >> command;
        if (command == "shoot") {
            soviet_division->shoot_all(global_observer);
        } else if (command == "go") {
            soviet_division->go_all();
        }

        int opponents_command = rand() % 2;
        if (opponents_command == 0) {
            german_division->shoot_all(global_observer);
        }
        else {
            german_division->go_all();
        }

        if (global_observer->if_you_lose()) {
            std::cout << "You Lose!";
            return 0;
        }

        if (global_observer->if_you_win()) {
            std::cout << "You Win!";
            return 0;
        }
    }
}
