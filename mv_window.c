#include "header.h"

void *mv_window(void* thread_data) {
    pthrData *data = (pthrData*) thread_data;
    int speed = 80000;
    
    while(1) {
        
        for (int rn = 1; rn < cols - 50; rn+=5) {
            int set = (rn % 2) ? 0 : 2;
            for (int i = 1; i < lines - lines / 10 - 1; i++) {

                if(((*data->x >= data->rand[rn] && *data->x <=data->rand[rn] + 10) 
                || (*data->x + 10 >= data->rand[rn] && *data->x + 10 <= data->rand[rn] + 10)) && ( *data->y < i + 5 && *data->y + 5 > i )) {
                    pthread_cancel(thread);
                    clear();
                    refresh();
                    //wprintw(data->prevstr, "PRESS ANY KEY TO FINISH GAME");
                    //wnoutrefresh(data->prevstr);
                    doupdate();               
                    getch();
                    endwin();
                    exit(0); 
                }
                wclear(data->win);
                wnoutrefresh(data->win);
                mvwin(data->win, i, data->rand[rn]);	
                window_print(data->win, 1, set);
                wnoutrefresh(data->win);
                doupdate();
                usleep(speed);
                
                if(speed > 50000) {
                    speed -= 100;
                } else {
                //    clear();
                //    doupdate();
                //    pause();
                }

            }
        }    
    }
}
