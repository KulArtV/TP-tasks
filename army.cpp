#include <vector>
#include "army.h"

vector<Infantry*> Army::get_infantry() {
    return infantry;
}

vector<Tank*> Army::get_tanks() {
    return tanks;
}

vector<Artillery*> Army::get_artillery() {
    return artillery;
}

vector<Rocket*> Army::get_rockets() {
    return ffp;
}

void Army::add_soldiers(vector<Infantry*> added) {
    for (auto soldier: added){
        infantry.push_back(soldier);
    }
}

void Army::add_tank(vector<Tank*> added) {
    for (auto tank: added){
        tanks.push_back(tank);
    }
}

void Army::add_artillery(vector<Artillery*> added) {
    for (auto artillery_unit: added){
        artillery.push_back(artillery_unit);
    }
}

Army::~Army() {
    infantry.clear();
    tanks.clear();
    artillery.clear();
    ffp.clear();
}

bool operator ==(const Army& a, const Army& b) {
    if (a.infantry.size() != b.infantry.size() || a.tanks.size() != b.tanks.size() ||
        a.artillery.size() != b.artillery.size()) {
        return false;
    }

    vector<Infantry*> inf_a, inf_b;
    for (auto unit : a.infantry) {
        inf_a.push_back(unit);
    }
    for (auto unit : b.infantry) {
        inf_b.push_back(unit);
    }
    for (int i = 0; i < inf_a.size(); ++i){
        if ((*inf_a[i]) != (*inf_b[i])) {
            return false;
        }
    }

    vector<Tank*> tank_a, tank_b;
    for (auto unit : a.tanks) {
        tank_a.push_back(unit);
    }
    for (auto unit : b.tanks) {
        tank_b.push_back(unit);
    }
    for (int i = 0; i < tank_a.size(); ++i){
        if ((*tank_a[i]) != (*tank_b[i])) {
            return false;
        }
    }

    vector<Artillery*> art_a, art_b;
    for (auto unit : a.artillery) {
        art_a.push_back(unit);
    }
    for (auto unit : b.artillery) {
        art_b.push_back(unit);
    }
    for (int i = 0; i < art_a.size(); ++i){
        if ((*art_a[i]) != (*art_b[i])) {
            return false;
        }
    }
    return true;
}

