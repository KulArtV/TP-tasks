#ifndef CONSTANTS_H
#define CONSTANTS_H

const int GAME_FIELD_SIZE = 200;
const int SOVIET_INFANTRY_SIZE = 30, GERMAN_INFANTRY_SIZE = 20;
const int SOVIET_TANKS = 15, GERMAN_TANKS = 20;
const int ARTILLERY = 4, ZONE = 20;
const int LIVES_DEFAULT = 40, GUN_DEFAULT = 3, TANK_DEFAULT = 15, ARTILLERY_DEFAULT = 30;
const double GUN_DEVIATION_DEFAULT = 0.02, ARTILLERY_DISPERSION_FUNCTION = 0.05, DEFAULT_SQUARE = 1;
const int TANK_DURATION = 2, ARTILLERY_DURATION = 10;
const int GROUPS_IN_ARMY = 4;
const char UP = 'w', LEFT = 'a', RIGHT = 'd', DOWN = 's';
const char SOVIET = 'S', GERMANY = 'G';
const int INF = static_cast<int>(2 * 1e9);


#endif
