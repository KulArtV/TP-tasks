#include "rocket.h"

Rocket::Rocket(){
    is_artillery = false;
    lives = LIVES_DEFAULT * 2;
    gun_power = ARTILLERY_DEFAULT * 2;
}

void Rocket::go(){
    
}

void Rocket::shoot(Visitor *v, Observer* obs){
    v->shootRocket(this, obs);
}

Rocket* Rocket::clone() const{
    return new Rocket(*this);
}