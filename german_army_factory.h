#ifndef GERMAN_ARMY_FACTORY_H
#define GERMAN_ARMY_FACTORY_H

#include "army_factory.h"

class GermanArmyFactory : public ArmyFactory {
public:
    vector<Infantry*> create_infantry() override;
    vector<Tank*> create_tanks() override;
    vector<Artillery*> create_artillery() override;
};

#endif
