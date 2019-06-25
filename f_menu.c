#include "header.h"

void f_menu(void) {
    WINDOW *menu;
    window_pref();
    menu = newwin(lines, cols, 0, 0);
    
    while(true) {
        box(menu, 0, 0);
        mvwprintw(menu, 24, 35, "PRESS ENTER TO START");
        mvwprintw(menu, 25, 35, "PRESS ESC TO EXIT");
        wnoutrefresh(menu);
        doupdate();
        switch(getch()) {
            case 10:
                clear();
                refresh();
                game_win();
                break;
            case 27:
                clear();
                refresh();
                endwin();
                curs_set(TRUE);
                exit(0);
        }
    }

}
