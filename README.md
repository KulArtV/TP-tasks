# Model of historical game

## Legend
Your army is going to have a fight with opponents team. Your army 
can shoot and go, opponent's army can do same. Army loses, if it 
doesn't have any units at all.

## Units

All types of units are created, according to factory pattern, from 
abstract unit class. Armies are created via abstract factory pattern.
Units can be grouped into subdivisions and be like one strong unit.
If artillery loses all it's health points, it becomes a Rocket.

## Regulations

Class Observer is created for regulations any events on field of play.
It helps armies to know about state of all army and lets each unit to
know about it's state.
Also, there s Visitor class to regulate any local fights beetween each
pair of units.

## Rules

In this version "go" method is not implemented, but method shoot works:
for each unit finds the nearest opponent's one, what is alive at that 
moment, after there is "fight" beetween them, which regulated via Visitor. 
After some shoots one army loses. Result of game depends on start position 
of each unit, but it generates randomly, so fight is randomly now:)

## Building

There is CMake file for building this project.
