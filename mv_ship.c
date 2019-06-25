#include "header.h"

void *mv_ship(void* thread_data) {
    pthrData *data = (pthrData*) thread_data;
    keypad(stdscr, true);
	curs_set(FALSE);
    noecho();
    int x = 45;
    int y = 43;

    while(1) {
        *data->x = x;
        *data->y = y;
       
        wclear(data->win);
        wnoutrefresh(data->win);
        mvwin(data->win, y, x);	
        window_print(data->win, 2, 1);
        wnoutrefresh(data->win);
        switch (getch()) {
            case KEY_UP:
          	    if(y > 1)
                    y--;
           		break;
	        case KEY_DOWN:
                if(y < 43)
                    y++;
                break;
            case KEY_LEFT:
                if(x > 1)
                    x--;
            	break;
            case KEY_RIGHT:
                if(x < 89)
                    x++;
                break;
        }
    }
}
