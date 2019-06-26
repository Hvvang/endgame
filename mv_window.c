#include "header.h"

void *mv_window(void* thread_data) {
    pthrData *data = (pthrData*) thread_data;
    int speed = 80000;
    int score = 0;
    while(1) {
        
        for (int rn = 1; rn < 90; rn++) {
            int set = (rn % 2) ? 0 : 2;
//            wclear(data->win);
//            wnoutrefresh(data->win2);
//            wprintw(data->win2, " SORE %d  ", score);
//            wnoutrefresh(data->win2);
//            doupdate();
            for (int i = 1; i < lines - lines / 10 - 1; i++) {

                if(mx_iscreck(*data->x, *data->y, data->rand[rn], i)) {
                    pthread_cancel(thread);
                    clear();
                    refresh();
                    doupdate();               
                    pthread_exit(NULL);
                }
                wclear(data->win);
                wnoutrefresh(data->win);
                mvwin(data->win, i, data->rand[rn]);	
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
