#include "subdivision.h"


Subdivision::Subdivision (Army* army) {
    vector<Infantry*> infantry = army->get_infantry();
    vector<Tank*> tanks = army->get_tanks();
    vector<Artillery*> artillery = army->get_artillery();
    vector<Rocket*> rocket = army->get_rockets();

    for (const auto& soldier : infantry) {
        subordinated_units.push_back(soldier);
    }
    for (const auto& gun : artillery) {
        subordinated_units.push_back(gun);
        subordinated_guns_only.push_back(gun);
    }
    for (const auto& dot : rocket) {
        subordinated_units.push_back(dot);
    }
    for (const auto& tank : tanks) {
        subordinated_units.push_back(tank);
    }
}

void Subdivision::add_unit(Unit* unit) {
    subordinated_units.push_back(unit);
}

void Subdivision::add_artillery(Artillery* unit) {
    subordinated_units.push_back(unit);
    subordinated_guns_only.push_back(unit);
}

void Subdivision::add_subdivision(Subdivision* subdivision) {
    subordinated_subdivisions.push_back(subdivision);
}

void Subdivision::remove_unit(Unit* unit) {
    vector<Unit*> new_units_list;
    for (auto element: subordinated_units) {
        if (element != unit) {
            new_units_list.push_back(element);
        }
    }
    subordinated_units = new_units_list;
}

void Subdivision::remove_gun(Artillery* unit) {
    remove_unit(unit);
    vector<Artillery*> new_guns_list;
    for (auto element: subordinated_guns_only) {
        if (element != unit) {
            new_guns_list.push_back(element);
        }
    }
    subordinated_guns_only = new_guns_list;
}

void Subdivision::remove_subdivision(Subdivision* subdivision) {
    vector<Subdivision*> new_subd_list;
    for (auto element: subordinated_subdivisions) {
        if (element != subdivision) {
            new_subd_list.push_back(element);
        }
    }
    subordinated_subdivisions = new_subd_list;
}

void Subdivision::shoot_all(Observer* obs){
    for (auto subd: subordinated_subdivisions){
        subd->shoot_all(obs);
    }
    for (auto unit: subordinated_units){
        auto v = new Visitor();
        unit->shoot(v, obs);
    }
}

void Subdivision::go_all() {
    for (auto subd: subordinated_subdivisions) {
        subd->go_all();
    }
    for (auto unit: subordinated_units) {
        unit->go();
    }
}

void Subdivision::transform_all_guns() {
    for (auto subd: subordinated_subdivisions) {
        subd->transform_all_guns();
    }

    vector<Unit*> new_units_list;
    vector<Artillery*> new_guns_list;

    for (auto unit: subordinated_units) {
        if (unit->is_artillery) {
            continue;
        } else {
            new_units_list.push_back(unit);
        }
    }

    for (auto artillery: subordinated_guns_only) {
        if (artillery->lives > 0) {
            new_guns_list.push_back(artillery);
            new_units_list.push_back(artillery);
        } else {
            ArtilleryAdapter* adapter = new ArtilleryAdapter(artillery);
            new_units_list.push_back(adapter->transform_to_rocket());
        }
    }
    subordinated_units = new_units_list;
    subordinated_guns_only = new_guns_list;
}

void Subdivision::divide() {
    vector<int> division_order;
    for (int i = 0; i < subordinated_units.size(); ++i) {
        division_order.push_back(i);
    }
    std::random_shuffle(division_order.begin(), division_order.end());
    if (division_order.size() < GROUPS_IN_ARMY){
        return;
    }
    for (int i = 0; i < GROUPS_IN_ARMY; ++i) {
        subordinated_subdivisions.push_back(new Subdivision());
    }
    for (int i = 0; i < division_order.size(); ++i){
        int index = division_order[i];
        if (index + subordinated_guns_only.size() < division_order.size()){
            Unit* unit = subordinated_units[index];
            subordinated_subdivisions[index % GROUPS_IN_ARMY]->add_unit(unit);
        }
    }
    for (int i = 0; i < division_order.size(); ++i){
        int index = division_order[i];
        if (index + subordinated_guns_only.size() >= division_order.size()){
            int other_size = division_order.size() - subordinated_guns_only.size();
            Artillery* gun = subordinated_guns_only[index - other_size];
            subordinated_subdivisions[division_order[i] % GROUPS_IN_ARMY]->add_artillery(gun);
        }
    }
    subordinated_units.clear();
    subordinated_guns_only.clear();
    for (int i = 0; i < subordinated_subdivisions.size(); ++i) {
        subordinated_subdivisions[i]->divide();
    }
}

vector<Unit*> Subdivision::get_all_units(){
    vector<Unit*> result = subordinated_units;
    for (auto subdivision: subordinated_subdivisions) {
        for (auto element : subdivision->get_all_units()) {
            result.push_back(element);
        }
    }
    return result;
}

Subdivision::~Subdivision(){
    subordinated_subdivisions.clear();
    subordinated_guns_only.clear();
    subordinated_units.clear();
}