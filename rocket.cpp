#include "rocket.h"

Rocket::Rocket(){
    is_artillery = false;
    ticks_to_next_shoot = 0;
}

void Rocket::go(){
    
}
void Rocket::shoot(Visitor *v){
    v->shootRocket(this);
}
Rocket* Rocket::clone() const{
    return new Rocket(*this);
}