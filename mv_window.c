#include "header.h"

void *mv_window(void* thread_data) {
    pthrData *data = (pthrData*) thread_data;
    int speed = 80000;
    int score = 0;
    int next_j = 0;
    int direction = 1;
    while(1) {
        
        for (int rn = 1; rn < 90; rn++) {
	    int j = data->rand[rn];
            int start_j = j;
            int set = (rn % 2) ? 0 : 2;
//            wclear(data->win);
//            wnoutrefresh(data->win2);
//            wprintw(data->win2, " SORE %d  ", score);
//            wnoutrefresh(data->win2);
//            doupdate();
            for (int i = 1; i < lines - lines / 10 - 1; i++) {
		int range = 8 + rand() % 40;
                if(mx_iscreck(*data->x, *data->y, j, i)) {
                    pthread_cancel(thread);
                    clear();
                    refresh();
                    doupdate();               
                    pthread_exit(NULL);
                }
                wclear(data->win);
                wnoutrefresh(data->win);
                //mvwin(data->win, i, data->rand[rn]);
		mvwin(data->win, i, j);
                next_j = j + direction;
    	        if (next_j >= start_j + range || next_j < start_j - range || next_j < 2 || next_j >= cols - 12 ) {
 		    direction*= -1;
 		} else {
 		    j+= direction;
 		}	
                window_print(data->win, 1, set);
                wnoutrefresh(data->win);
                doupdate();
                usleep(speed);
                
                if(speed > 70000) {
                    speed -= 100;
                } else {
                    wclear(data->win2);
                    wnoutrefresh(data->win2);
                    int sec_ship = 90 - data->rand[rn];
                    mvwin(data->win2, i, sec_ship);
                    window_print(data->win2, 1, set);
                    wnoutrefresh(data->win2);
                    doupdate();
                    if(mx_iscreck(*data->x, *data->y, sec_ship, i)) {
                        pthread_cancel(thread);
                        clear();
                        refresh();
                        doupdate();               
                        pthread_exit(NULL);
                    }
                }

            }
            score++;
        }    
    }
}
