#ifndef HEADER
#define HEADER

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t  thread3, thread, enemy;

typedef struct{
	WINDOW	*win;
	int *rand;
	int *x;
	int *y;
} pthrData;

static int arr[90];
static int cols = 100;
static int lines = 50;
static const char ships[3][6][10] = {
    {    " _|____|_ ",
        "/[ ==== ]\\",
        "\\[ ==== ]/",
        "+ :----: +",
        "|  :--:  |",
        "*  \\**/  *"
	},
	{
    	"    .     ",
    	"   / \\    ",
   		"---.|.--- ",
    	" /|   |\\  ",
    	"/ |   | \\ ",
    	"\\/\\|||/\\/ ",
	},
	{
        "    __    ",
        "_ / || \\ _",
        "^ \\ || / ^",
        " | \\**/ | ",
        "  \\ || /  ",
        " / \\**/ \\ "
	}
};

void window_pref(void);
void window_print(WINDOW *win, int color_pair, int set);
void window_filling(WINDOW *win);
void *mv_window(void* thread_data);
void interface(WINDOW *ui);
void destroy_win(WINDOW *local_win);
void *mv_ship(void* thread_data);
void *f_rand(void *param);
void game_win();

#endif
