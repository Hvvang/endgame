#include "header.h"

void print_space_map(void){
    WINDOW *sm = newwin(28, 56, 0, 0);
    mvwin(sm, 14, 20);
    box(sm, '|', ' ');
    wmove(sm, 1, 11);
    waddch(sm, '.');
    wrefresh(sm);
    //---------------
    wmove(sm, 17, 43);
    waddch(sm, '.');
    wrefresh(sm);
    //---------------
    wmove(sm, 12, 12);
    waddch(sm, ' ');
    wrefresh(sm);
}
