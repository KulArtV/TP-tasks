#include "game.cpp"
#include "constants.h"
#include "soviet_army_factory.h"
#include "german_army_factory.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>


using std::vector;

Army* hand_create(const char country){
    if (country == 'S') {
        Army* hand_created_army = new Army();
        vector<Infantry*> soldiers;
        for (int i = 0; i < SOVIET_INFANTRY_SIZE; ++i) {
            soldiers.push_back(new Infantry());
        }
        hand_created_army->add_soldiers(soldiers);
        vector<Tank*> tanks;
        for (int i = 0; i < SOVIET_TANKS; ++i){
            tanks.push_back(new Tank());
        }
        hand_created_army->add_tank(tanks);
        vector<Artillery*> guns;
        for (int i = 0; i < ARTILLERY; ++i) {
            guns.push_back(new Artillery());
        }
        hand_created_army->add_artillery(guns);
        return hand_created_army;
    } else {
        Army* hand_created_army = new Army();
        vector<Infantry*> soldiers;
        for (int i = 0; i < GERMAN_INFANTRY_SIZE; ++i) {
            soldiers.push_back(new Infantry());
        }
        hand_created_army->add_soldiers(soldiers);
        vector<Tank*> tanks;
        for (int i = 0; i < GERMAN_TANKS; ++i) {
            tanks.push_back(new Tank());
        }
        hand_created_army->add_tank(tanks);
        vector<Artillery*> guns;
        for (int i = 0; i < ARTILLERY; ++i) {
            guns.push_back(new Artillery());
        }
        hand_created_army->add_artillery(guns);
        return hand_created_army;
    }

}

::testing::AssertionResult IsEqual(Army* a, Army* b) {
	if ((*a) == (*b)) {
        return ::testing::AssertionSuccess();
	}
	else {
        return ::testing::AssertionFailure();
	}
}

TEST(ARMY_CREATING, SA) {
    Game game;
    SovietArmyFactory s_factory;
    EXPECT_TRUE(IsEqual(game.create_army(s_factory), hand_create(SOVIET)));
}

TEST(ARMY_CREATING, GA) {
    Game game;
    GermanArmyFactory g_factory;
    EXPECT_TRUE(IsEqual(game.create_army(g_factory), hand_create(GERMANY)));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
