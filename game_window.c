#include "header.h"

void game_win(void) {
    int x_ship, y_ship;
	int score = 0;
    WINDOW *game_window, *enemy_ship, *ship, *ship2, *score_window, *ship3;

    game_window = newwin(lines, cols, 0, 0 );
	box(game_window, 0, 0);
	enemy_ship = subwin(game_window, 6 , 10, 2, 3);
	ship = subwin(game_window, 6 , 10, 43, 45);
    ship2 = subwin(game_window, 6 , 10, 2, 30);
	ship3 = subwin(game_window, 6 , 10, 2, 15);
	score_window = subwin(game_window, 6 , 10, 24, 35);

	wnoutrefresh(stdscr);
    wnoutrefresh(game_window);

    doupdate();

	pthrData struct_ship;
	struct_ship.win = ship;
	struct_ship.x = &x_ship;
	struct_ship.y = &y_ship;
  	
	pthread_create(&thread3, NULL, f_rand, (void *)arr);
	
	pthrData struct_enemy;
	struct_enemy.win = enemy_ship;
    struct_enemy.win2 = ship2;
	struct_enemy.win3 = ship3; 
	struct_enemy.score = &score;
	struct_enemy.rand = arr;
	struct_enemy.x = &x_ship;
	struct_enemy.y = &y_ship;
	
	pthread_create(&thread, NULL, mv_ship, (void *)&struct_ship);
	pthread_create(&enemy, NULL, mv_window, (void *)&struct_enemy);
	pthread_join(enemy, NULL);
	box(game_window, 0, 0);
	wnoutrefresh(game_window);
	wprintw(score_window, " SCORE %d  ", score);
    wnoutrefresh(score_window);
	doupdate();
    usleep(5000000);
}
