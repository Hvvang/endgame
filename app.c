#include "header.h"

int main() {
	//system("open prev.mp3");
	initscr();

	WINDOW *ui = newwin(60, 170, 0, 0);      
	interface(ui);
	f_menu();

	endwin();
}
