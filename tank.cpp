#include "tank.h"

Tank::Tank() {
    x = rand() % ZONE + 1;
    y = rand()% (GAME_FIELD_SIZE + 1);
    lives = LIVES_DEFAULT;
    gun_power = TANK_DEFAULT;
}

void Tank::go() {

}

void Tank::shoot(Visitor *v, Observer* obs) {
    v->shootTank(this, obs);
}

Tank* Tank::clone() const {
    return new Tank(*this);
}

bool operator !=(const Tank& a, const Tank& b){
    if (a.x != b.x || a.y != b.y) {
        return true;
    }
    return false;
}