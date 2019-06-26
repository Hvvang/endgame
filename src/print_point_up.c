#include "header.h"

void print_point_up(int y, int x,int color) {
       WINDOW *map = newwin(1, 1, 0, 0);
       mvwin(map, 15, x);
       wclear(map);
       wnoutrefresh(map);
     //------------------
       mvwin(map, 23, x);
       wclear(map);
       wnoutrefresh(map);
     //------------------
       mvwin(map, 17, x);
       wclear(map);
       wnoutrefresh(map);
     //-------------------
       mvwin(map, 18, x);
       wclear(map);
       wnoutrefresh(map);
     //-------------------
       mvwin(map, y + 1, x);
       wclear(map);
       wnoutrefresh(map);
     //--------------------
       //if(x % 2 == 0) y += 1;
      // if(x % 2 == 1) x -= 1;
       mvwin(map, y, x);
       wattron(map, COLOR_PAIR(color));
       waddch(map, '.');
       wnoutrefresh(map);
}
