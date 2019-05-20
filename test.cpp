#include "game.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

const bool SOVIET = true, GERMAN = false;

Army* hand_create(bool if_soviet){
    Army* test = new Army();
    vector<Infantry*> inf;
    for (int i=0; i < SOVIET_SOLDIERS; i++){
        inf.push_back(new Infantry());
    }
    test->add_soldiers(inf);
    vector<Tank*> tnk;
    for (int i=0; i < SOVIET_TANKS; i++){
        tnk.push_back(new Tank());
    }
    test->add_tank(tnk);
    vector<Artillery*> art;
    for (int i=0; i < ARTILLERY; i++){
        art.push_back(new Artillery());
    }
    test->add_artillery(art);
    return test;
    vector<Aviation*> avia;
    for (int i=0; i < AVIATION; i++){
        avia.push_back(new Aviation());
    }
    test->add_aviation(avia);
    return test;
}

::testing::AssertionResult IsEqual(Army* a, Army* b)
{
	if ((*a) == (*b))
		return ::testing::AssertionSuccess();
	else
		return ::testing::AssertionFailure();
}

TEST(Test, SA)
{
    Game game;
    SovietArmyFactory s_factory;
    EXPECT_TRUE(IsEqual(game.create_army(s_factory), hand_create(SOVIET)));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}