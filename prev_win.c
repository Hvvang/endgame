#include "header.h"

void interface(WINDOW *ui){
    keypad(stdscr, true);
    window_pref();
    // color initial;

    
    //-----------------------------------

    // Start text
    char src[] = "Hi dude!";
    char src2[] = "I think you are tired and want to relax a bit";
    char src3[] = "This is what you need!";
    char src4[] = "Do it!"; 
    //-----------------------------------------------------------  
    box(ui, 0, 0);
    //firs array
    wmove(ui, 5, 20);
    wattron(ui, COLOR_PAIR(4));
    for(int i = 0; i < 8; i++){
        waddch(ui, src[i]);
        wrefresh(ui);
        usleep(100000);
    }
    wmove(ui, 6, 20);
    wattron(ui, COLOR_PAIR(3));
    for(int i = 0; i < 45; i++){
        waddch(ui, src2[i]);
        wrefresh(ui);
        usleep(80000);
    }
    wmove(ui, 7, 20);
    wattron(ui, COLOR_PAIR(2));
    for(int i = 0; i < 22; i++){
        waddch(ui, src3[i]);
        wrefresh(ui);
        usleep(100000);
    }
    wmove(ui, 8, 20);
    wattron(ui, COLOR_PAIR(4));
    for(int i = 0; i < 6; i++){
         waddch(ui, src4[i]);
         wrefresh(ui);
         usleep(100000);
    }
    //-----------------------------------------------------------
    char arr[16][110] = {
"+----------------------------------------------------------------------------------------------------------+\n",
"|                                                                                                          |\n",
"|                                                                                                          |\n",
"|    @@@@@@   @@@@@@@    @@@@@@    @@@@@@@  @@@@@@@@     @@@@@@@   @@@  @@@  @@@       @@@        @@@@@@   |\n",
"|   @@@@@@@   @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@     @@@@@@@@  @@@  @@@  @@@       @@@       @@@@@@@   |\n",
"|   !@@       @@!  @@@  @@!  @@@  !@@       @@!          @@!  @@@  @@!  @@@  @@!       @@!       !@@       |\n",
"|   !@!       !@!  @!@  !@!  @!@  !@!       !@!          !@   @!@  !@!  @!@  !@!       !@!       !@!       |\n",
"|   !!@@!!    @!@@!@!   @!@!@!@!  !@!       @!!!:!       @!@!@!@   @!@  !@!  @!!       @!!       !!@@!!    |\n",
"|    !!@!!!   !!@!!!    !!!@!!!!  !!!       !!!!!:       !!!@!!!!  !@!  !!!  !!!       !!!        !!@!!!   |\n",
"|        !:!  !!:       !!:  !!!  :!!       !!:          !!:  !!!  !!:  !!!  !!:       !!:            !:!  |\n",
"|      !:!   :!:       :!:  !:!  :!:       :!:          :!:  !:!  :!:  !:!   :!:       :!:          !:!    |\n",
"|  :::: ::    ::       ::   :::   ::: :::   :: ::::      :: ::::  ::::: ::   :: ::::   :: ::::  :::: ::    |\n",
"|  :: : :     :         :   : :   :: :: :  : :: ::      :: : ::    : :  :   : :: : :  : :: : :  :: : :     |\n",
"|                                                                                                          |\n",
"|                                                                                                          |\n",
"+----------------------------------------------------------------------------------------------------------+\n"
};
    int s = 30;
    wattron(ui, COLOR_PAIR(1));
    for (int i = 0; i < 16; i++){
        wmove(ui, s, 20);
        waddstr(ui, arr[i]);
        wrefresh(ui);
        usleep(60000);
        s++;
    } 
    // wrefresh(ui); 
    sleep(5);
    clear();
    refresh();
}
