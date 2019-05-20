#include "artillery_adapter.h"

ArtilleryAdapter::ArtilleryAdapter(Artillery* gun) {
    destroyed_gun = gun;
}

Rocket* ArtilleryAdapter::transform_to_rocket() {
    auto rocket = new Rocket();
    rocket->x = destroyed_gun->x;
    rocket->y = destroyed_gun->y;
    rocket->gun_power = destroyed_gun->gun_power / 2;
    return rocket;
}