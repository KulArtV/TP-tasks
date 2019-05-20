#ifndef ARTILLERY_H
#define ARTILLERY_H

#include <iostream>
#include "unit.h"

class Artillery: public Unit{
    friend bool operator !=(const Artillery& a, const Artillery& b);

    public:
        Artillery();
        void shoot(Visitor *v, Observer* obs) override;
        void go() override ;
        Artillery* clone() const override;
};

#endif

