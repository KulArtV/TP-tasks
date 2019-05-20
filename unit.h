#ifndef UNIT_H
#define UNIT_H


#include "visitor.h"
#include "constants.h"


class Unit {
    public:
        int x;
        int y;
        int lives = LIVES_DEFAULT;
        int gun_power;
        bool is_soviet;
        bool is_artillery;
        virtual void go() = 0;
        virtual void shoot(Visitor* v, Observer* obs) = 0;
        virtual Unit* clone() const = 0;
};

#endif
