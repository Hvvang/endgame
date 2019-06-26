#include "header.h"

bool mx_iscreck(int x_ship, int y_ship, int x_enemy, int y_enemy) {
    return ((x_ship >= x_enemy && x_ship <= x_enemy + 10)
            || (x_ship + 10 >= x_enemy && x_ship + 10 <= x_enemy + 10)) && ( y_ship < y_enemy + 5 && y_ship + 5 > y_enemy) ? true : false;
}
