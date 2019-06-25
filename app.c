#include "header.h"

int main() {
	initscr();

	WINDOW *ui = newwin(60, 170, 0, 0);      
	interface(ui);
	f_menu();
	// game_win();

	endwin();
}
