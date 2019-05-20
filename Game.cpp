#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

const int FIELD = 150, SOVIET_SOLDIERS = 5, SOVIET_TANKS = 1,
                       GERMAN_SOLDIERS = 3, GERMAN_TANKS = 2, ARTILLERY = 2, AVIATION = 4, ZONE = 10;
const int LIVES_DEFAULT = 50, GUN_DEFAULT = 5, TANK_DEFAULT = 10, ARTILLERY_DEFAULT=20;
const double GUN_DEVIATION_DEFAULT = 0.03, ARTILLERY_DISPERSION_FUNCTION = 0.03, DEFAULT_SQUARE = 1;

class Unit{
public:
    int x;
    int y;
    int lives;
    int gun_power;
    virtual void go(int dx, int dy) = 0;
    virtual void shoot(int target_x, int target_y) const = 0;
    virtual Unit* clone() const = 0;
};

class Infantry : public Unit{
    friend bool operator !=(const Infantry& a, const Infantry& b);

public:
    double gun_deviation_percent;
    Infantry() {
        x = rand() % ZONE + 1;
        y = rand() % (FIELD + 1);
        lives = LIVES_DEFAULT;
        gun_power = GUN_DEFAULT;
        gun_deviation_percent = GUN_DEVIATION_DEFAULT;
    }

    void go(int dx, int dy) {};
    void shoot(int target_x, int target_y) const {};
    Infantry* clone() const {
        return new Infantry(*this);
    }
};

class Tank : public Unit{
    friend bool operator !=(const Tank& a, const Tank& b);

public:
    double deviation_percent;
    int ticks_to_next_shoot;
    Tank() {
        x = rand() % ZONE + 1;
        y = rand() % (FIELD + 1);
        lives = LIVES_DEFAULT;
        gun_power = TANK_DEFAULT;
        deviation_percent = GUN_DEVIATION_DEFAULT * 2.0;
        ticks_to_next_shoot=0;
    }

    void go(int dx, int dy){};
    void shoot(int target_x, int target_y) const {};
    Tank* clone() const{
        return new Tank(*this);
    }
};

class Artillery: public Unit{
    friend bool operator !=(const Artillery& a, const Artillery& b);

public:
    double dispersion;
    double square;
    int ticks_to_next_shoot;
    Artillery() {
        x = 0;
        y = rand() % (FIELD + 1);
        lives = LIVES_DEFAULT;
        gun_power = ARTILLERY_DEFAULT;
        square = DEFAULT_SQUARE;
        dispersion = ARTILLERY_DISPERSION_FUNCTION;
        ticks_to_next_shoot = 0;
    }
    void shoot(int target_x, int target_y) const {};
    void go(int dx, int dy){
        assert(0);
    }
    Artillery* clone() const{
        return new Artillery(*this);
    }
};

class Aviation: public Unit{
    friend bool operator !=(const Artillery& a, const Artillery& b);

public:
    double dispersion;
    int ticks_to_next_flight;
    Aviation() {
        x = 0;
        y = rand() % (FIELD + 1);
        lives = LIVES_DEFAULT;
        gun_power = ARTILLERY_DEFAULT / 2;
        dispersion = ARTILLERY_DISPERSION_FUNCTION * 2;
        ticks_to_next_flight = 1;
    }
    void shoot(int target_x, int target_y) const {};
    void go(int dx, int dy){
        assert(0);
    }
    Aviation* clone() const{
        return new Aviation(*this);
    }
};

class Army{
    friend bool operator ==(const Army& a, const Army& b);

private:
    vector<Infantry*> infantry;
    vector<Tank*> tanks;
    vector<Artillery*> artillery;
    vector<Aviation*> aviation;

public:
    void add_soldiers(vector<Infantry*> added){
        for (auto soldier: added){
            infantry.push_back(soldier);
        }
    }
    void add_tank(vector<Tank*> added){
        for (auto tank: added){
            tanks.push_back(tank);
        }
    }
    void add_artillery(vector<Artillery*> added){
        for (auto artillery_unit: added){
            artillery.push_back(artillery_unit);
        }
    }
    void add_aviation(vector<Aviation*> added){
        for (auto aviation_unit: added){
            aviation.push_back(aviation_unit);
        }
    }
    ~Army(){
        infantry.clear();
        tanks.clear();
        artillery.clear();
        aviation.clear();
    }
};

bool operator !=(const Infantry& a, const Infantry& b){
    if (a.lives != b.lives || a.gun_deviation_percent != b.gun_deviation_percent || a.gun_power != b.gun_power) {
        return true;
    } else {
        return false;
    }
}

bool operator !=(const Tank& a, const Tank& b){
    if (a.lives != b.lives || a.deviation_percent != b.deviation_percent ||
        a.gun_power != b.gun_power || a.ticks_to_next_shoot != b.ticks_to_next_shoot) {
        return true;
    } else {
        return false;
    }
}

bool operator !=(const Artillery& a, const Artillery& b){
    if (a.lives != b.lives || a.dispersion != b.dispersion || a.square!=b.square ||
        a.gun_power != b.gun_power || a.ticks_to_next_shoot != b.ticks_to_next_shoot) {
        return true;
    } else {
        return false;
    };

}

bool operator !=(const Aviation& a, const Aviation& b){
    if (a.lives != b.lives || a.dispersion != b.dispersion ||
        a.gun_power != b.gun_power || a.ticks_to_next_flight != b.ticks_to_next_flight) {
        return true;
    } else {
        return false;
    };

}

bool operator ==(const Army& a, const Army& b) {
    if (a.infantry.size() != b.infantry.size() || a.tanks.size() != b.tanks.size() ||
        a.artillery.size() != b.artillery.size()) {
        return false;
    }

    vector<Infantry*> inf_a, inf_b;
    for (auto unit : a.infantry) inf_a.push_back(unit);
    for (auto unit : b.infantry) inf_b.push_back(unit);
    for (int i=0; i < inf_a.size(); i++){
        if ((*inf_a[i]) != (*inf_b[i])) return false;
    }

    vector<Tank*> tank_a, tank_b;
    for (auto unit : a.tanks) tank_a.push_back(unit);
    for (auto unit : b.tanks) tank_b.push_back(unit);
    for (int i=0; i < tank_a.size(); i++){
        if ((*tank_a[i]) != (*tank_b[i])) return false;
    }

    vector<Artillery*> art_a, art_b;
    for (auto unit : a.artillery) art_a.push_back(unit);
    for (auto unit : b.artillery) art_b.push_back(unit);
    for (int i=0; i < art_a.size(); i++){
        if ((*art_a[i]) != (*art_b[i])) return false;
    }

    vector<Aviation*> avia_a, avia_b;
    for (auto unit : a.aviation) avia_a.push_back(unit);
    for (auto unit : b.aviation) avia_b.push_back(unit);
    for (int i=0; i < art_a.size(); i++){
        if ((*art_a[i]) != (*art_b[i])) return false;
    }
    return true;
}

class ArmyFactory{
public:
    virtual vector<Infantry*> create_infantry() = 0;
    virtual vector<Tank*> create_tanks() = 0;
    virtual vector<Artillery*> create_artillery() = 0;
    virtual vector<Aviation*> create_aviation() = 0;
};


class SovietArmyFactory : public ArmyFactory{
public:
    vector<Infantry*> create_infantry() override {
        vector<Infantry*> arr;
        for (int i = 0; i < SOVIET_SOLDIERS; i++){
            arr.push_back(new Infantry());
        }
        return arr;
    }
    vector<Tank*> create_tanks() override {
        vector<Tank*> arr;
        for (int i = 0; i < SOVIET_TANKS; i++){
            arr.push_back(new Tank());
        }
        return arr;
    }
    vector<Artillery*> create_artillery() override {
        vector<Artillery*> arr;
        for (int i = 0; i < ARTILLERY; i++){
            arr.push_back(new Artillery());
        }
        return arr;
    }
    vector<Aviation*> create_aviation() override {
        vector<Aviation*> avia;
        for (int i = 0; i < AVIATION; i++){
            avia.push_back(new Aviation());
        }
        return avia;
    }
};

class GermanArmyFactory : public ArmyFactory{
public:
    vector<Infantry*> create_infantry(){
        vector<Infantry*> arr;
        for (int i = 0; i < GERMAN_SOLDIERS; i++){
            arr.push_back(new Infantry());
            arr.back()->x = FIELD - arr.back()->x;
        }
        return arr;
    }
    vector<Tank*> create_tanks(){
        vector<Tank*> arr;
        for (int i = 0; i < GERMAN_TANKS; i++){
            arr.push_back(new Tank());
            arr.back()->x = FIELD - arr.back()->x;
        }
        return arr;
    }
    vector<Artillery*> create_artillery(){
        vector<Artillery*> arr;
        for (int i = 0; i < ARTILLERY; i++){
            arr.push_back(new Artillery());
            arr.back()->x = FIELD - arr.back()->x;
        }
        return arr;
    }
    vector<Aviation*> create_aviation(){
        vector<Aviation*> avia;
        for (int i = 0; i < ARTILLERY; i++){
            avia.push_back(new Aviation());
            avia.back()->x = FIELD - avia.back()->x;
        }
        return avia;
    }
};

class Game{
public:
    Army* create_army(ArmyFactory &factory){
        Army* new_army = new Army();
        new_army->add_soldiers(factory.create_infantry());
        new_army->add_tank(factory.create_tanks());
        new_army->add_artillery(factory.create_artillery());
        new_army->add_aviation(factory.create_aviation());
        return new_army;
    }
};

int run(){
    Game game;
    SovietArmyFactory s_factory;
    Army* soviet_army = game.create_army(s_factory);
    GermanArmyFactory g_factory;
    Army* german_army = game.create_army(g_factory);
    cout << "You have done it" << endl;
    return 0;
}