#include "header.h"

void window_pref(void) {
    noecho();
    curs_set(FALSE);
    keypad(stdscr, true);
    start_color();
	has_colors();
	init_pair(1,  COLOR_RED,   COLOR_BLACK);
	init_pair(2,  COLOR_WHITE,   COLOR_BLACK);
}
