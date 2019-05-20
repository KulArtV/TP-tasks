#include "german_army_factory.h"

vector<Infantry*> GermanArmyFactory::create_infantry() {
    vector<Infantry*> soldiers;
    for (int i = 0; i < GERMAN_INFANTRY_SIZE; ++i) {
        soldiers.push_back(new Infantry());
        soldiers.back()->x = GAME_FIELD_SIZE-soldiers.back()->x;
        soldiers.back()->is_soviet = false;
    }
    return soldiers;
}
vector<Tank*> GermanArmyFactory::create_tanks() {
    vector<Tank*> tanks;
    for (int i = 0; i < GERMAN_TANKS; ++i) {
        tanks.push_back(new Tank());
        tanks.back()->x = GAME_FIELD_SIZE - tanks.back()->x;
        tanks.back()->is_soviet = false;
    }
    return tanks;
}
vector<Artillery*> GermanArmyFactory::create_artillery() {
    vector<Artillery*> guns;
    for (int i = 0; i < ARTILLERY; ++i) {
        guns.push_back(new Artillery());
        guns.back()->x = GAME_FIELD_SIZE - guns.back()->x;
        guns.back()->is_soviet = false;
    }
    return guns;
}