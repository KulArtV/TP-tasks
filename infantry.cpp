#include "infantry.h"


Infantry::Infantry(){
    x = rand() % ZONE + 1;
    y = rand() % (GAME_FIELD_SIZE + 1);
    is_artillery = false;
    lives = LIVES_DEFAULT;
    gun_power = GUN_DEFAULT;
    gun_deviation_percent = GUN_DEVIATION_DEFAULT;
}

void Infantry::go() {

}

void Infantry::shoot(Visitor *v) {
    v->shootSoldier(this);
}

Infantry* Infantry::clone() const {
    return new Infantry(*this);
}

bool operator !=(const Infantry& a, const Infantry& b) {
    if (a.lives != b.lives || a.gun_power != b.gun_power ||
        a.gun_deviation_percent != b.gun_deviation_percent) {
        return true;
    }
    return false;
}

