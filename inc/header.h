#ifndef HEADER
#define HEADER

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <locale.h>

pthread_t  thread3, thread, enemy;

typedef struct{
	WINDOW *win;
    WINDOW *win2;
	WINDOW *win3;
	WINDOW *state_score;
	WINDOW *state_health;
	int *score;
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

int mx_strlen(const char *s);
void window_pref(void);
void print_point(int y, int x, int color);
void print_point_t(int y, int x, int color);
void print_point_up(int y, int x,int color);
void print_space_map(void);
void print_ship(int x);
void last_hope(WINDOW *ui);
void print_story(WINDOW *ui);
void fire_anim(WINDOW *ui, char arr[12][62]);
void interface(WINDOW *ui);
void window_print(WINDOW *win, int color_pair, int set);
void about(WINDOW *about_win);
void menu(void);
void window_filling(WINDOW *win);
void *mv_window(void* thread_data);
void interface(WINDOW *ui);
bool mx_iscreck(int x_ship, int y_ship, int x_enemy, int y_enemy);
void destroy_win(WINDOW *local_win);
void *mv_ship(void* thread_data);
void *f_rand(void *param);
void game_win();
void window_state(pthrData *data, int score, int hp);
void menu_filling(WINDOW *menu_win, int *i, char *item, char **list);

#endif
