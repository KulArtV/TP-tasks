#include "visitor.h"
#include "infantry.h"
#include "tank.h"
#include "artillery.h"
#include "rocket.h"

void Visitor::shootSoldier(Infantry *soldier) {
    std::cout << soldier->x << '\n';
}

void Visitor::shootTank(Tank *tank) {
    std::cout << tank->x << '\n';
}

void Visitor::shootArt(Artillery* gun) {
    std::cout << gun->x << '\n';
}

void Visitor::shootRocket(Rocket* rocket){
    std::cout << rocket->x << '\n';
}
