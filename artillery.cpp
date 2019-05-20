#include "artillery.h"

Artillery::Artillery() {
    is_artillery = false;
    x = 0;
    y = rand()%(GAME_FIELD_SIZE+1);
    lives = LIVES_DEFAULT;
    gun_power = ARTILLERY_DEFAULT;
    square = DEFAULT_SQUARE;
    dispersion = ARTILLERY_DISPERSION_FUNCTION;
    ticks_to_next_shoot=0;
}

void Artillery::shoot(Visitor *v) {
    v->shootArt(this);
}

void Artillery::go() {

}

Artillery* Artillery::clone() const {
    return new Artillery(*this);
}

bool operator !=(const Artillery& a, const Artillery& b) {
    if (a.lives != b.lives || a.dispersion != b.dispersion || a.square != b.square ||
        a.gun_power != b.gun_power || a.ticks_to_next_shoot != b.ticks_to_next_shoot) {
        return true;
    }
    return false;
}
