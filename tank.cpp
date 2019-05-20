#include "tank.h"

Tank::Tank() {
    x = rand() % ZONE + 1;
    y = rand()% (GAME_FIELD_SIZE + 1);
    lives = LIVES_DEFAULT;
    gun_power = TANK_DEFAULT;
    deviation_percent = GUN_DEVIATION_DEFAULT * 2;
    ticks_to_next_shoot = 0;
}

void Tank::go() {

}

void Tank::shoot(Visitor *v) {
    v->shootTank(this);
}

Tank* Tank::clone() const {
    return new Tank(*this);
}

bool operator !=(const Tank& a, const Tank& b){
    if (a.lives != b.lives || a.deviation_percent != b.deviation_percent ||
        a.gun_power != b.gun_power || a.ticks_to_next_shoot != b.ticks_to_next_shoot) {
        return true;
    }
    return false;
}