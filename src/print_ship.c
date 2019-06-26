#include "header.h"

void print_ship(int x) {
    WINDOW *ship = newwin(4, 10, 0, 0);
    char sh[4][10] = {
       "   /\\   \n",  
       "  /||\\  \n",                                
       "~ *__* ~\n",
       "   ||   \n"
    };
    box(ship, 0, 0);
    mvwin(ship, 35, x);
    for(int i = 0; i < 4; i++){
        waddstr(ship, sh[i]);
    }
    wrefresh(ship);
}
