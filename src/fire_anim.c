#include "header.h"

void fire_anim(WINDOW *ui, char arr[12][62]){
 
     int h = 19;
     int crue = 0;
     int v = 9; 
     int pointy = 15;
     int pointx = 20;
     int yup = 33;
     int color = 2;
     int ship = 43;
     int dr = 1;
     int ch = 0;
     for(int i = 6; i > 0; i--){
        curs_set(0);
        wattron(ui, COLOR_PAIR(5));
        wmove(ui, v, h);
        waddstr(ui, arr[i]);
        print_space_map();
        if(ch == 90){
             wclear(ui);
             wrefresh(ui); 
             break;
        }    
        if(color == 5) color = 1;
        if(pointy == 35) pointy = 15;
        if(yup == 14) yup = 35;
        if(ship == 53) dr = -1;
        if(ship == 32) dr = 1;
        ship += dr;
        print_point(pointy, pointx + 5, color);
        //--------------------------------------
        print_point(pointy + 8, pointx + 17, color);
        //--------------------------------------
        print_point_t(pointy + 2, pointx + 32, color);
        //--------------------------------------
        print_point_t(pointy + 3, pointx + 50, color);
        //--------------------------------------
        print_point(pointy + 2, pointx + 8, color);
        //--------------------------------------
        print_point(pointy + 4, pointx + 21, color);
        //--------------------------------------
        print_point_t(pointy + 2, pointx + 38, color);
        //--------------------------------------
        print_point_t(pointy + 3, pointx + 46, color);
        //--------------------------------------
        print_point_up(yup, pointx + 11, color);
        //----------------------------------------
        print_point_up(yup + 8, pointx + 24, color);
        //--------------------------------------------
        print_point_up(yup + 2, pointx + 42, color + 1);
        //-----------------------------------------------
        print_point_up(yup + 3, pointx + 52, color + 1);
        //----------------------------------------------
        print_ship(ship);
        wrefresh(ui);
        usleep(100000);
        v--;
        crue++;
        pointy++;
        yup--;
        color++;
        ch++;
        if(crue == 6) h = 20;
        if(crue == 12){
            h = 19;
            crue = 0;
        }
        if(v == 4){
            v = 9;
            i = 7;
        }    
     }
     print_story(ui);
}
