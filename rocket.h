#ifndef FFP_H
#define FFP_H

#include "unit.h"


class Rocket: public Unit {
public:
    Rocket();
    void go() override ;
    void shoot(Visitor *v, Observer* obs) override ;
    Rocket* clone() const override ;
};

#endif
