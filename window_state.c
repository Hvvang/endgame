#include "header.h"

void window_state(pthrData *data, int score, int hp) {
    wclear(data->state_score);
    wclear(data->state_health);
    wnoutrefresh(data->state_score);
    wnoutrefresh(data->state_health);
    wprintw(data->state_score, " SCORE: %i  ", score);
    wprintw(data->state_health, "   HEALTH: %i ", hp);
    wnoutrefresh(data->state_score);
    wnoutrefresh(data->state_health);

    wnoutrefresh(data->win3);
    wnoutrefresh(data->win2);
    wnoutrefresh(data->win);
    doupdate();
}
