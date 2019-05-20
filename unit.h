#ifndef UNIT_H
#define UNIT_H


#include "visitor.h"

class Unit {

    public:
        int x;
        int y;
        bool is_artillery;
        virtual void go() = 0;
        virtual void shoot(Visitor* v) = 0;
        virtual Unit* clone() const = 0;
};

#endif
