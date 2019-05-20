#include "visitor.h"
#include "infantry.h"
#include "tank.h"
#include "artillery.h"
#include "rocket.h"
#include "observer.h"

void Visitor::shootSoldier(Infantry *soldier, Observer* obs) {
    Unit* opponent_unit = obs->get_closest(soldier);
    if (opponent_unit == nullptr) {
        return;
    }
    if (opponent_unit->is_soviet) {
        std::cout << "Opponent's soldier shoot in opponent unit with coordinates " << opponent_unit->x << ' ' << opponent_unit->y << '\n';
    } else {
        std::cout << "Your soldier shoot in opponent unit with coordinates " << opponent_unit->x << ' ' << opponent_unit->y << '\n';
    }
    opponent_unit->lives -= soldier->gun_power;
    if (opponent_unit->lives <= 0) {
        obs->remove_unit(opponent_unit, opponent_unit->is_soviet);
        if (opponent_unit->is_soviet) {
            std::cout << "Opponent's soldier won the battle!!!\n";
        } else {
            std::cout << "Your soldier won the battle!!!\n";
        }
        obs->recalc_distances();
    }
}

void Visitor::shootTank(Tank *tank, Observer* obs) {
    Unit* opponent_unit = obs->get_closest(tank);
    if (opponent_unit == nullptr) {
        return;
    }
    if (opponent_unit->is_soviet) {
        std::cout << "Opponent's tank shoot in opponent unit with coordinates " << opponent_unit->x << ' ' << opponent_unit->y << '\n';
    } else {
        std::cout << "Your tank shoot in opponent unit with coordinates " << opponent_unit->x << ' ' << opponent_unit->y << '\n';
    }
    opponent_unit->lives -= tank->gun_power;
    if (opponent_unit->lives <= 0) {
        obs->remove_unit(opponent_unit, opponent_unit->is_soviet);
        if (opponent_unit->is_soviet) {
            std::cout << "Opponent's tank won the battle!!!\n";
        } else {
            std::cout << "Your tank won the battle!!!\n";
        }
        obs->recalc_distances();
    }
}

void Visitor::shootArt(Artillery* gun, Observer* obs) {
    Unit* opponent_unit = obs->get_closest(gun);
    if (opponent_unit == nullptr) {
        return;
    }
    if (opponent_unit->is_soviet) {
        std::cout << "Opponent's artillery shoot in opponent unit with coordinates " << opponent_unit->x << ' ' << opponent_unit->y << '\n';
    } else {
        std::cout << "Your artillery shoot in opponent unit with coordinates " << opponent_unit->x << ' ' << opponent_unit->y << '\n';
    }
    opponent_unit->lives -= gun->gun_power;
    if (opponent_unit->lives <= 0) {
        obs->remove_unit(opponent_unit, opponent_unit->is_soviet);
        if (opponent_unit->is_soviet) {
            std::cout << "Opponent's artillery won the battle!!!\n";
        } else {
            std::cout << "Your artillery won the battle!!!\n";
        }
        obs->recalc_distances();
    }
}

void Visitor::shootRocket(Rocket* rocket, Observer* obs) {
    Unit* opponent_unit = obs->get_closest(rocket);
    if (opponent_unit == nullptr) {
        return;
    }
    if (opponent_unit->is_soviet) {
        std::cout << "Opponent's rocket shoot in opponent unit with coordinates " << opponent_unit->x << ' ' << opponent_unit->y << '\n';
    } else {
        std::cout << "Your rocket shoot in opponent unit with coordinates " << opponent_unit->x << ' ' << opponent_unit->y << '\n';
    }
    opponent_unit->lives -= rocket->gun_power;
    if (opponent_unit->lives <= 0) {
        obs->remove_unit(opponent_unit, opponent_unit->is_soviet);
        if (opponent_unit->is_soviet) {
            std::cout << "Opponent's rocket won the battle!!!\n";
        } else {
            std::cout << "Your rocket won the battle!!!\n";
        }
        obs->recalc_distances();
    }
}
