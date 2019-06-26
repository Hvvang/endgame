#include "header.h"

void *mv_ship(void* thread_data) {
    pthrData *data = (pthrData*) thread_data;
    window_pref();
    int x = 45;
    int y = 43;
    int i = 3;
    while(1) {
        *data->x = x;
        *data->y = y;
       
        wclear(data->win);
        wnoutrefresh(data->win);
        mvwin(data->win, y, x);	
        window_print(data->win, i, 1);
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
                if(x > 2)
                    x--;
            	    break;
            case KEY_RIGHT:
                if(x < 88)
                    x++;
                    break;
            case 'c' :
                if(i == 4)
                    i = 1;
                ++i;
        }
    }
}
