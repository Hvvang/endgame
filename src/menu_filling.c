#include "header.h"

void menu_filling(WINDOW *menu_win, int *i, char *item, char **list) {
    box(menu_win, 0, 0);
	for (*i = 0; *i < 3; (*i)++){
		if (*i == 0)
			wattron(menu_win, A_STANDOUT);
		else{
			wattroff(menu_win, A_STANDOUT);
		}
		sprintf(item, "%-3s",  list[*i]);
		mvwprintw(menu_win, *i + 24, 48, "%s", item);
	}
	wrefresh(menu_win);
	*i = 0;
}
