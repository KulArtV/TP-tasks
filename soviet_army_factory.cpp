#include "soviet_army_factory.h"

vector<Infantry*> SovietArmyFactory::create_infantry() {
    vector<Infantry*> soldiers;
    for (int i = 0; i < SOVIET_INFANTRY_SIZE; ++i) {
        soldiers.push_back(new Infantry());
        soldiers.back()->is_soviet = true;
    }

    return soldiers;
}

vector<Tank*> SovietArmyFactory::create_tanks() {
    vector<Tank*> tanks;
    for (int i = 0; i < SOVIET_TANKS; ++i){
        tanks.push_back(new Tank());
        tanks.back()->is_soviet = true;
    }
    return tanks;
}

vector<Artillery*> SovietArmyFactory::create_artillery() {
    vector<Artillery*> guns;
    for (int i = 0; i < ARTILLERY; ++i){
        guns.push_back(new Artillery());
        guns.back()->is_soviet = true;
    }
    return guns;
}