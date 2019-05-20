#ifndef GAME_H
#define GAME_H

#include "visitor.h"
#include "unit.h"
#include "observer.h"
#include "tank.h"
#include "artillery.h"
#include "rocket.h"
#include "subdivision.h"
#include "army.h"
#include "german_army_factory.h"
#include "soviet_army_factory.h"
#include "constants.h"

class Game {
public:
    Army* create_army(ArmyFactory &factory);
};

#endif
