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

		        mvwin(data->win, i, j);
                next_j = j + direction;
    	        if (next_j >= start_j + range || next_j < start_j - range || next_j < 2 || next_j >= cols - 12 ) {
 		            direction*= -1;
 		        } else {
 		            j+= direction;
 		        }	
                window_print(data->win, 1, set);
;
              
                if(speed > 78000) {
                    speed -= 100;
                } 
                if(score > 3) {
                    wclear(data->win2);
                    wnoutrefresh(data->win2);
                    int sec_ship = 90 - data->rand[rn];
                    mvwin(data->win2, i, sec_ship);
                    window_print(data->win2, 1, set);
 
                    if(mx_iscreck(*data->x, *data->y, sec_ship, i)) {
                        pthread_cancel(thread);
                        clear();
                        refresh();

                        doupdate(); 
                        pthread_exit(NULL);
                    }
                }
                if(score > 7) {
                    wclear(data->win3);
                    wnoutrefresh(data->win3);
                    mvwin(data->win3, i, data->rand[rn]);
                    window_print(data->win3, 1, set);
 
                    if(mx_iscreck(*data->x, *data->y, data->rand[rn], i)) {
                        pthread_cancel(thread);
                        clear();
                        refresh();

                        doupdate(); 
                        pthread_exit(NULL);
                    }
                }
                wnoutrefresh(data->win3);
                wnoutrefresh(data->win2);
                wnoutrefresh(data->win);
                doupdate();
                usleep(speed);
            }
            score++;
            *data -> score = score;
        }    
    }
}
