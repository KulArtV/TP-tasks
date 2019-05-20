#ifndef CONSTANTS_H
#define CONSTANTS_H

const int GAME_FIELD_SIZE = 40;
const int SOVIET_INFANTRY_SIZE = 5, GERMAN_INFANTRY_SIZE = 4;
const int SOVIET_TANKS = 1, GERMAN_TANKS = 2;
const int ARTILLERY = 4, ZONE = 1;
const int LIVES_DEFAULT = 8, GUN_DEFAULT = 2, TANK_DEFAULT = 5, ARTILLERY_DEFAULT = 10;
const double GUN_DEVIATION_DEFAULT = 0.02, ARTILLERY_DISPERSION_FUNCTION = 0.05, DEFAULT_SQUARE = 1;
const int GROUPS_IN_ARMY = 4;
const char UP = 'w', LEFT = 'a', RIGHT = 'd', DOWN = 's';
const char SOVIET = true, GERMANY = false;
const int INF = static_cast<int>(2 * 1e9);

#endif
