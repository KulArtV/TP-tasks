#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>
#include "constants.h"
#include "unit.h"


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
    ~Observer();

private:
    void remove_from_vector(vector<Unit*> &line, vector<Unit*> closest, Unit* unit);
};

#endif
