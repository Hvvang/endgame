#include "header.h"

void window_print(WINDOW *win, int color_pair, int set) {
    for(int i = 0; i < 7; i++) {
       	for (int j = 0; j < 10; j++) {
        	mvwaddch(win ,i, j, ships[set][i][j]  | COLOR_PAIR(color_pair));
		}
	}
}
