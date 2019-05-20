#ifndef ARMY_FACTORY_H
#define ARMY_FACTORY_H

#include <iostream>
#include <vector>
#include "infantry.h"
#include "tank.h"
#include "artillery.h"

using std::vector;

class ArmyFactory{
public:
    virtual vector<Infantry*> create_infantry() = 0;
    virtual vector<Tank*> create_tanks() = 0;
    virtual vector<Artillery*> create_artillery() = 0;
};



#endif
