#include "header.h"

void *mv_window(void* thread_data) {
    setlocale(LC_CTYPE, "");

    pthrData *data = (pthrData*) thread_data;
    int speed = 80000;
    int score = 0;
    int next_j = 0;
    int direction = 1;
    int hp = 3;
    int sign = 1;
    while(1) {
        for (int rn = 1; rn < 90; rn++) {
	        int j = data->rand[rn];
            int start_j = j;
            int set = (rn % 2) ? 0 : 2;

            for (int i = 2; i < lines - lines / 10 - 1; i++) {
		        int range = 8 + rand() % 40;
                if(mx_iscreck(*data->x, *data->y, j, i)) {
                    write(1, "\a", 1);
                    hp--;
                    sign = 0;
                    break;
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
                        write(1, "\a", 1);
                        hp--;
                        sign = 0;
                        break;
                    }
                    
                }
                if(score > 7) {
                    wclear(data->win3);
                    wnoutrefresh(data->win3);
                    mvwin(data->win3, i, data->rand[rn]);
                    window_print(data->win3, 1, set);
 
                    if(mx_iscreck(*data->x, *data->y, data->rand[rn], i)) {
                        write(1, "\a", 1);
                        hp--;
                        sign = 0;
                        break;
                    }
                }
                if(hp == 0) {
                    pthread_cancel(thread);
                    clear();
                    refresh();
                    doupdate(); 
                    pthread_exit(NULL);
                }
                window_state(data, score, hp);
                usleep(speed);
            }
            if(sign) { 
                score++;
            } else {
                sign = 1;
            }
            *data -> score = score;
        }    
    }
}
