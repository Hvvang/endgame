#include "header.h"

void print_point(int y, int x, int color) {
    WINDOW *map = newwin(1, 1, 0, 0);
    mvwin(map, 34, x);
    wclear(map);
    wnoutrefresh(map);
   //------------------
    mvwin(map, 42, x);
    wclear(map);
    wnoutrefresh(map);
   //-------------------
    mvwin(map, y - 1, x);
    wclear(map); 
    wnoutrefresh(map);
  //--------------------
    mvwin(map, y, x);
    wattron(map, COLOR_PAIR(color));
    waddch(map, '.');
    wnoutrefresh(map);
}
