#ifndef SUBDIVISION_H
#define SUBDIVISION_H

#include "army.h"
#include "artillery_adapter.h"


class Subdivision {
    vector<Subdivision*> subordinated_subdivisions;
    vector<Unit*> subordinated_units;
    vector<Artillery*> subordinated_guns_only;

public:
    Subdivision(Army* army);
    Subdivision() = default;

    void add_unit(Unit* unit);
    void add_artillery(Artillery* unit);
    void add_subdivision(Subdivision* subdivision);

    void remove_unit(Unit* unit);
    void remove_gun(Artillery* unit);
    void remove_subdivision(Subdivision* subdivision);

    void shoot_all();
    void go_all();
    void transform_all_guns();
    ~Subdivision();
};

#endif
