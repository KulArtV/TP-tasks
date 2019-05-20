#ifndef TANK_H
#define TANK_H

#include <iostream>
#include "unit.h"
#include "constants.h"

class Tank : public Unit {

    public:
        int lives;
        int gun_power;
        double deviation_percent;
        int ticks_to_next_shoot;
        Tank();
        void go() override;
        void shoot(Visitor *v) override ;
        Tank* clone() const override;
        friend bool operator !=(const Tank& a, const Tank& b);
};

#endif
