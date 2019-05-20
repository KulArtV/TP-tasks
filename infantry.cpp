#include "infantry.h"


Infantry::Infantry(){
    x = rand() % ZONE + 1;
    y = rand() % (GAME_FIELD_SIZE + 1);
    is_artillery = false;
    gun_power = GUN_DEFAULT;
}

void Infantry::go() {

}

void Infantry::shoot(Visitor *v, Observer* obs) {
    v->shootSoldier(this, obs);
}

Infantry* Infantry::clone() const {
    return new Infantry(*this);
}

bool operator !=(const Infantry& a, const Infantry& b) {
    if (a.x != b.x || a.y != b.y) {
        return true;
    }
    return false;
}

