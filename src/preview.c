#include "header.h"

void interface(WINDOW *ui) {
    window_pref();
 
    box(ui, 0, 0);

//  Print array -----------------------------------------------

    char arr[12][62] = {
"                                                          ",
"                                                          ",
"  (   (                                   (    (    (     ",
"  )\\ ))\\ )   (       (           (        )\\ ) )\\ ) (\\ )  ",
" (()/(()/(   )\\      )\\  (     ( )\\    ( (()/((()/((()/(  ",
"  /(_)/(_)((((_)(  (((_) )\\    )((_)   )\\ /(_))/(_))/(_)) ",
" (_))(_))  )\\ _ )\\ )\\___((_)  ((_)_ _ ((_(_)) (_)) (_))   ",
" / __| _ \\   /_\\   (/ __| __|  | _ | | | | |  | |  / __|  ",
" \\__ |  _/  / _ \\  | (__| _|   | _ | |_| | |__| |__\\__ \\  ",
" |___|_|   /_/ \\_\\  \\___|___|  |___/\\___/|____|____|___/  ",
"                                                          ",
"                                                            "
};
    int v = 3;
    for (int i = 0; i < 12; i++){
        wmove(ui, v, 20);
        if( i == 1) wattron(ui, COLOR_PAIR(8));
        if( i == 12)  wattron(ui, COLOR_PAIR(8));
        if(i > 2 && i < 7){
            wattron(ui, COLOR_PAIR(5));
        }else{
            wattron(ui, COLOR_PAIR(1));
        }
        waddstr(ui, arr[i]);
        wrefresh(ui);
        usleep(80000);
        v++;
    }
//--------------------------------------------------------------------------


// Animation array ------
   // print_space_map();
    fire_anim(ui, arr);

//-------------------------
    
    while(1){
      wrefresh(ui);   
    } 
}
