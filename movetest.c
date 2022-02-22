#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void interruptHandler(int sig){
        endwin();
        printf("this program will be exited in 3 seconds..\n");
        sleep(3);
        exit(0);
}

// void GotoXY(int x, int y)
// {
// 		move(y,x);
// }

void PrintMovingObj(row,col)
{
    int pos = 0;
    int dir = +1;

    while(1){

    move(pos,col/2);
    printw("ㅁ");
    refresh();
    usleep(100000);
    move(pos,col/2);
    erase();
    pos += dir;
    if (pos >= row-1){
        dir = -1;
    }
    if (pos <= 0){
        dir = +1;
    }
    }
}

int main(void)
{
    int row, col = 0;
    signal(SIGINT, interruptHandler);
    setlocale(LC_ALL, "");
    initscr();
    curs_set(0);
    getmaxyx(stdscr,row,col);

    refresh();

    PrintMovingObj(row,col);
    

    // move(row-2,0);
    // printw("press any key to exit...");
    // refresh();
    // getch();
    endwin();

    return 0;
}
