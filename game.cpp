#include "game.h"

Army* Game::create_army(ArmyFactory &factory){
    Army* new_army = new Army();
    new_army->add_soldiers(factory.create_infantry());
    new_army->add_tank(factory.create_tanks());
    new_army->add_artillery(factory.create_artillery());
    return new_army;
}