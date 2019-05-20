#ifndef SOVIET_ARMY_FACTORY_H
#define SOVIET_ARMY_FACTORY_H

#include "army_factory.h"

class SovietArmyFactory : public ArmyFactory{
public:
    vector<Infantry*> create_infantry() override;
    vector<Tank*> create_tanks() override;
    vector<Artillery*> create_artillery() override;
};

#endif
