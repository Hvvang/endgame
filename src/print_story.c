#include "header.h"

void print_story(WINDOW *ui) {
    WINDOW *st = newwin(50, 100, 0, 0);
    box(st, 0, 0);
    char line[32] = {"A long time ago in a galaxy far,"};
    char line1[39] = {"far away peace and tranquility reigned."};
    char line2[25] = {"But it did not last long."};
    char line3[74] = {"The planet of space bulls, which was once peaceful, became a battleground."};
    char line4[36] = {"Guardians were dying one by one and"};
    char line5[56] = {"today the last space bull will face hordes of enemies..."};
    int x = 20;
    for(int i = 0; i < 32; i++){
        wattron(st, COLOR_PAIR(5));       
        mvwaddch(st, 20, x, line[i]);
        usleep(60000);
        wrefresh(st);
        x++;
    }
    x = 20; 
    for(int i = 0; i < 39; i++){
        wattron(st, COLOR_PAIR(5));        
        mvwaddch(st,21, x + 2,line1[i]);
        usleep(40000);
        wrefresh(st);
        x++;
    }
    x = 20;
    for(int i = 0; i < 25; i++){
        wattron(st, COLOR_PAIR(3));       
        mvwaddch(st, 22, x, line2[i]);
        usleep(60000);
        wrefresh(st);
        x++;
    }
    x = 20;
    for(int i = 0; i < 74; i++){
       wattron(st, COLOR_PAIR(2));    
       mvwaddch(st, 23, x, line3[i]);
       usleep(20000);
       wrefresh(st);
       x++;
    }
    x = 20;
    for(int i = 0; i < 35; i++){
        wattron(st, COLOR_PAIR(2));        
        mvwaddch(st, 24, x, line4[i]);
        usleep(60000);
        wrefresh(st);
        x++;  
    }
    x = 20;
    for(int i = 0; i < 56; i++){
         wattron(st, COLOR_PAIR(1));        
         mvwaddch(st,25, x, line5[i]);
         usleep(60000);
         wrefresh(st);
         x++; 
    }
    usleep(4000000);
    last_hope(ui);
    
}
