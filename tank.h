#ifndef TANK_H
#define TANK_H

#include <iostream>
#include "unit.h"

class Tank : public Unit {

    public:
        Tank();
        void go() override;
        void shoot(Visitor *v, Observer* obs) override;
        Tank* clone() const override;
        friend bool operator !=(const Tank& a, const Tank& b);
};

#endif
