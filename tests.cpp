#include "game.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>


TEST(GAME_RESULT, SOVIET_WIN_WITHOUT_RESISTANCE) {
    Game game;
    SovietArmyFactory s_factory;
    Army* soviet_army = game.create_army(s_factory);
    GermanArmyFactory g_factory;
    Army* german_army = game.create_army(g_factory);
    std::cout << "Armies are created\n";
    Subdivision* soviet_division = new Subdivision(soviet_army);
    Subdivision* german_division = new Subdivision(german_army);
    soviet_division->divide();
    german_division->divide();
    std::cout << "Armies are divided and ready to battle\n";
    Observer* global_observer = new Observer();
    vector<Unit*> all_soviet = soviet_division->get_all_units();
    vector<Unit*> all_german = german_division->get_all_units();

    for (auto unit: all_soviet){
        global_observer->add_unit(unit, SOVIET);
    }
    for (auto unit: all_german){
        global_observer->add_unit(unit, GERMANY);
    }
    global_observer->recalc_distances();

    soviet_division->shoot_all(global_observer);
    soviet_division->shoot_all(global_observer);
    soviet_division->shoot_all(global_observer);
    soviet_division->shoot_all(global_observer);
    EXPECT_TRUE(global_observer->if_you_win());
}

TEST(GAME_RESULT, SOVIET_LOSE_WITHOUT_RESISTANCE) {
    Game game;
    SovietArmyFactory s_factory;
    Army* soviet_army = game.create_army(s_factory);
    GermanArmyFactory g_factory;
    Army* german_army = game.create_army(g_factory);
    std::cout << "Armies are created\n";
    Subdivision* soviet_division = new Subdivision(soviet_army);
    Subdivision* german_division = new Subdivision(german_army);
    soviet_division->divide();
    german_division->divide();
    std::cout << "Armies are divided and ready to battle\n";
    Observer* global_observer = new Observer();
    vector<Unit*> all_soviet = soviet_division->get_all_units();
    vector<Unit*> all_german = german_division->get_all_units();

    for (auto unit: all_soviet){
        global_observer->add_unit(unit, SOVIET);
    }
    for (auto unit: all_german){
        global_observer->add_unit(unit, GERMANY);
    }
    global_observer->recalc_distances();

    soviet_division->shoot_all(global_observer);
    EXPECT_TRUE(!global_observer->if_you_win());
}

TEST(GAME_RESULT, GERMAN_WIN_WITHOUT_RESISTANCE) {
    Game game;
    SovietArmyFactory s_factory;
    Army* soviet_army = game.create_army(s_factory);
    GermanArmyFactory g_factory;
    Army* german_army = game.create_army(g_factory);
    std::cout << "Armies are created\n";
    Subdivision* soviet_division = new Subdivision(soviet_army);
    Subdivision* german_division = new Subdivision(german_army);
    soviet_division->divide();
    german_division->divide();
    std::cout << "Armies are divided and ready to battle\n";
    Observer* global_observer = new Observer();
    vector<Unit*> all_soviet = soviet_division->get_all_units();
    vector<Unit*> all_german = german_division->get_all_units();

    for (auto unit: all_soviet){
        global_observer->add_unit(unit, SOVIET);
    }
    for (auto unit: all_german){
        global_observer->add_unit(unit, GERMANY);
    }
    global_observer->recalc_distances();

    german_division->shoot_all(global_observer);
    german_division->shoot_all(global_observer);
    german_division->shoot_all(global_observer);
    german_division->shoot_all(global_observer);
    EXPECT_TRUE(global_observer->if_you_lose());
}

TEST(GAME_RESULT, GERMAN_LOSE_WITHOUT_RESISTANCE) {
    Game game;
    SovietArmyFactory s_factory;
    Army* soviet_army = game.create_army(s_factory);
    GermanArmyFactory g_factory;
    Army* german_army = game.create_army(g_factory);
    std::cout << "Armies are created\n";
    Subdivision* soviet_division = new Subdivision(soviet_army);
    Subdivision* german_division = new Subdivision(german_army);
    soviet_division->divide();
    german_division->divide();
    std::cout << "Armies are divided and ready to battle\n";
    Observer* global_observer = new Observer();
    vector<Unit*> all_soviet = soviet_division->get_all_units();
    vector<Unit*> all_german = german_division->get_all_units();

    for (auto unit: all_soviet){
        global_observer->add_unit(unit, SOVIET);
    }
    for (auto unit: all_german){
        global_observer->add_unit(unit, GERMANY);
    }
    global_observer->recalc_distances();

    german_division->shoot_all(global_observer);
    EXPECT_TRUE(!global_observer->if_you_lose());
}

TEST(GAME_RESULT, SOVIET_GERMAN_SOVIET_SHOOT) {
    Game game;
    SovietArmyFactory s_factory;
    Army* soviet_army = game.create_army(s_factory);
    GermanArmyFactory g_factory;
    Army* german_army = game.create_army(g_factory);
    std::cout << "Armies are created\n";
    Subdivision* soviet_division = new Subdivision(soviet_army);
    Subdivision* german_division = new Subdivision(german_army);
    soviet_division->divide();
    german_division->divide();
    std::cout << "Armies are divided and ready to battle\n";
    Observer* global_observer = new Observer();
    vector<Unit*> all_soviet = soviet_division->get_all_units();
    vector<Unit*> all_german = german_division->get_all_units();

    for (auto unit: all_soviet){
        global_observer->add_unit(unit, SOVIET);
    }
    for (auto unit: all_german){
        global_observer->add_unit(unit, GERMANY);
    }
    global_observer->recalc_distances();

    soviet_division->shoot_all(global_observer);
    german_division->shoot_all(global_observer);
    soviet_division->shoot_all(global_observer);
    EXPECT_TRUE(global_observer->if_you_win());
}

TEST(GAME_RESULT, SOVIET_GERMAN_SOVIET_GERMAN_SHOOT) {
    Game game;
    SovietArmyFactory s_factory;
    Army* soviet_army = game.create_army(s_factory);
    GermanArmyFactory g_factory;
    Army* german_army = game.create_army(g_factory);
    std::cout << "Armies are created\n";
    Subdivision* soviet_division = new Subdivision(soviet_army);
    Subdivision* german_division = new Subdivision(german_army);
    soviet_division->divide();
    german_division->divide();
    std::cout << "Armies are divided and ready to battle\n";
    Observer* global_observer = new Observer();
    vector<Unit*> all_soviet = soviet_division->get_all_units();
    vector<Unit*> all_german = german_division->get_all_units();

    for (auto unit: all_soviet){
        global_observer->add_unit(unit, SOVIET);
    }
    for (auto unit: all_german){
        global_observer->add_unit(unit, GERMANY);
    }
    global_observer->recalc_distances();

    soviet_division->shoot_all(global_observer);
    german_division->shoot_all(global_observer);
    soviet_division->shoot_all(global_observer);
    german_division->shoot_all(global_observer);
    EXPECT_TRUE(global_observer->if_you_win());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
