#ifndef GAG_TANK_ADAPTER_H
#define GAG_TANK_ADAPTER_H

#include "artillery.h"
#include "rocket.h"

class ArtilleryAdapter {
private:
    Artillery* destroyed_gun;
public:
    explicit ArtilleryAdapter(Artillery* gun);
    Rocket* transform_to_rocket();
};

#endif
