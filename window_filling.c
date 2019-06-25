#include "header.h"

void window_filling(WINDOW *win) {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 10; j++) {
				mvwprintw(win, i, j, "X");
		}
	}
}
