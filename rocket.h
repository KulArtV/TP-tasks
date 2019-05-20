#ifndef FFP_H
#define FFP_H

#include "unit.h"
#include "visitor.h"

class Rocket: public Unit {
public:
    int gun_power;
    int ticks_to_next_shoot;
    Rocket();
    void go();
    void shoot(Visitor *v);
    Rocket* clone() const;
};

#endif
