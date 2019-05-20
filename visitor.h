#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>

class Infantry;
class Tank;
class Artillery;
class Rocket;
class Observer;

class Visitor {
    public:
        void shootSoldier(Infantry* soldier, Observer* obs);
        void shootTank(Tank* tank, Observer* obs);
        void shootArt(Artillery* art, Observer* obs);
        void shootRocket(Rocket* ffp, Observer* obs);
};

#endif
