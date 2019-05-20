#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>
#include "constants.h"
#include "army.h"

using std::vector;


class Observer {

public:
    vector<Unit*> soviet_subscribers;
    vector<Unit*> german_subscribers;
    vector<Unit*> closest_to_soviet;
    vector<Unit*> closest_to_german;

    void add_unit(Unit* unit, bool if_soviet);
    void remove_unit(Unit* unit, bool if_soviet);
    void recalc_distances();
    int get_dist(Unit* a, Unit* b);
    Unit* get_closest(Unit* unit);
    ~Observer();

    bool if_you_lose();
    bool if_you_win();

private:
    void remove_from_vector(vector<Unit*> &line, vector<Unit*> closest, Unit* unit);
};

#endif
