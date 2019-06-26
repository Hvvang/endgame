#include "header.h"

int main() {
	//system("open prev.mp3");
	initscr();
	WINDOW *ui = newwin(50, 100, 0, 0);      
    interface(ui);

	endwin();
}
