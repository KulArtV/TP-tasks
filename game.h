#ifndef GAME_H
#define GAME_H

#include "army.h"
#include "soviet_army_factory.h"
#include "german_army_factory.h"
#include "observer.h"
#include "artillery_adapter.h"
#include "subdivision.h"

class Game {

public:
    Army* create_army(ArmyFactory &factory);
};

#endif
