#include "header.h"

void about(WINDOW *about_win){
	int button;
	start_color();
     init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	char src[] = "Created by: mlibovych";
	char src1[] = "ashemidko";
	char src2[] = "ybelyaev";
	char src3[] = "vtryzna";
	char src4[] = "vbabiak";
	char src5[] = "spolienko";
	char src6[] = "This game is a final team project at Ucode Marathon";
	char src7[] = "press ESC to exit";
	wclear(about_win);
	box(about_win, 0, 0);

	wmove(about_win, 5, 10);
	wattron(about_win, COLOR_PAIR(1));
	curs_set(0);
    for(int i = 0; i < 21; i++){
        waddch(about_win, src[i]);
        wrefresh(about_win);
        usleep(50000);
    }

	wmove(about_win, 6, 22);
	wattron(about_win, COLOR_PAIR(1));
     for(int i = 0; i < 9; i++){
          waddch(about_win, src1[i]);
          wrefresh(about_win);
          usleep(50000);
     }

	wmove(about_win, 7, 22);
     wattron(about_win, COLOR_PAIR(1));
     for(int i = 0; i < 8; i++){
          waddch(about_win, src2[i]);
          wrefresh(about_win);
          usleep(50000);
     }

	wmove(about_win, 8, 22);
     wattron(about_win, COLOR_PAIR(1));
     for(int i = 0; i < 7; i++){
         waddch(about_win, src3[i]);
         wrefresh(about_win);
          usleep(50000);
     }

	wmove(about_win, 9, 22);
     wattron(about_win, COLOR_PAIR(1));
    for(int i = 0; i < 7; i++){
          waddch(about_win, src4[i]);
          wrefresh(about_win);
          usleep(50000);
     }

	wmove(about_win, 10, 22);
     wattron(about_win, COLOR_PAIR(1));
     for(int i = 0; i < 9; i++){
          waddch(about_win, src5[i]);
          wrefresh(about_win);
          usleep(50000);
     }

	wmove(about_win, 13, 10);
    wattron(about_win, COLOR_PAIR(1));
	for(int i = 0; i < 42; i++){
         waddch(about_win, src6[i]);
         wrefresh(about_win);
         usleep(50000);
    }

	wmove(about_win, 40, 10);
    wattron(about_win, COLOR_PAIR(2));
    for(int i = 0; i < 17; i++){
         waddch(about_win, src7[i]);
         wrefresh(about_win);
         usleep(50000);
    }
	
    wrefresh(about_win);
	keypad(about_win, TRUE);
	while (1){
	if ((button = wgetch(about_win)) == 27){ // bspace
		wclear(about_win);
		wrefresh(about_win);
		return;
		}
	}
}
