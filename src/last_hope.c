#include "header.h"

void last_hope(WINDOW *ui) {
    box(ui, 0, 0);
    start_color();
    nodelay(ui, TRUE);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);

    char src1[] = "You are the last hope of this doomed world!";    

    box(ui, 0, 0);
    wmove(ui, 24, 30);
    wattron(ui, COLOR_PAIR(1));
    for(int i = 0; i < mx_strlen(src1); i++){
        waddch(ui, src1[i]);
        wrefresh(ui);
        usleep(100000);
    }
    usleep(800000);
    menu();
}
