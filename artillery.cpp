#include "artillery.h"

Artillery::Artillery() {
    is_artillery = false;
    x = 0;
    y = rand()%(GAME_FIELD_SIZE+1);
    lives = LIVES_DEFAULT;
    gun_power = ARTILLERY_DEFAULT;
}

void Artillery::shoot(Visitor *v, Observer* obs) {
    v->shootArt(this, obs);
}

void Artillery::go() {

}

Artillery* Artillery::clone() const {
    return new Artillery(*this);
}

bool operator !=(const Artillery& a, const Artillery& b) {
    if (a.x != b.x || a.y != b.y) {
        return true;
    }
    return false;
}
