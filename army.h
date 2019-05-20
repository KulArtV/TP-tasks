#ifndef ARMY_H
#define ARMY_H

#include <vector>
#include "infantry.h"
#include "tank.h"
#include "artillery.h"
#include "rocket.h"

using std::vector;

class Army {
    friend bool operator ==(const Army& a, const Army& b);

    vector<Infantry*> infantry;
    vector<Tank*> tanks;
    vector<Artillery*> artillery;
    vector<Rocket*> ffp;

public:
    vector<Infantry*> get_infantry();
    vector<Tank*> get_tanks();
    vector<Artillery*> get_artillery();
    vector<Rocket*> get_rockets();
    void add_soldiers(vector<Infantry*> added);
    void add_tank(vector<Tank*> added);
    void add_artillery(vector<Artillery*> added);
    ~Army();
};

#endif
