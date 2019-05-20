#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>

class Infantry;
class Tank;
class Artillery;
class Rocket;

class Visitor{
    public:
        void shootSoldier(Infantry* soldier);
        void shootTank(Tank* tank);
        void shootArt(Artillery* art);
        void shootRocket(Rocket* ffp);
};

#endif
