#include "header.h"

void menu(void){
    window_pref();

    WINDOW *menu_win = newwin(50, 100, 0, 0);    
    keypad(menu_win, TRUE);
	char *list[] = {
						"START",
						"ABOUT",
						"EXIT",
						};
	char item[6];
	int button = 0;
	int i = 0;
	WINDOW *about_win = newwin(50, 100, 0, 0);
	menu_filling(menu_win, &i, item, list);
	while ((button = wgetch(menu_win)) != 'q'){ //esc
		sprintf(item, "%-3s",  list[i]);
		mvwprintw(menu_win, i + 24, 48, "%s", item);
		switch (button) {
			case KEY_UP:
				i--;
				if (i < 0)
					i = 2;
				break;
			case KEY_DOWN:
				i++;
				if (i > 2)
					i = 0;
				break;
			case 10: //enter
				if (i == 0){
                    wclear(menu_win);
					wrefresh(menu_win);
					game_win();
                    menu_filling(menu_win, &i, item, list);
				}
				if (i == 1){
					i = 0;
					wclear(menu_win);
					wrefresh(menu_win);
					about(about_win);
					menu_filling(menu_win, &i, item, list);
				}
				if (i == 2){
					endwin();
					exit(0);
				}
				break;
			case 27:
				endwin();
				exit(0);
		}
		wattron(menu_win, A_STANDOUT);
		sprintf(item, "%-3s",  list[i]);
		mvwprintw(menu_win, i + 24, 48, "%s", item);
		wattroff(menu_win, A_STANDOUT);
	}
}
