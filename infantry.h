#ifndef INFANTRY_H
#define INFANTRY_H

#include <iostream>
#include "unit.h"
#include "constants.h"

class Infantry : public Unit {
    friend bool operator!=(const Infantry& a, const Infantry& b);
    public:
        int lives;
        int gun_power;
        double gun_deviation_percent;
        Infantry();
        void go();
        void shoot(Visitor *v);
        Infantry* clone() const;
};

#endif

