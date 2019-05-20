#ifndef INFANTRY_H
#define INFANTRY_H

#include <iostream>
#include "unit.h"
#include "constants.h"

class Infantry : public Unit {
    friend bool operator!=(const Infantry& a, const Infantry& b);

public:
        Infantry();
        void go() override;
        void shoot(Visitor *v, Observer* obs) override;
        Infantry* clone() const override;
};

#endif

