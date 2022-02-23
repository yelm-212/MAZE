#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

// keyboard input
#define LEFT 68
#define RIGHT 67
#define UP 65
#define DOWN 66
#define ARROW 27
#define ARROW2 91

void interruptHandler(int sig){
        endwin();
        printf("this program will be exited in 2 seconds..\n");
        sleep(2);
        exit(0);
}

// void GotoXY(int x, int y)
// {
// 		move(y,x);
// }

void PrintMovingObj(int row,int col);
void MoveMaze(int row,int col,int y,int x);

int main(void)
{
    int row, col = 0;
    signal(SIGINT, interruptHandler);
    setlocale(LC_ALL, "");
    initscr();
    curs_set(0);
    getmaxyx(stdscr,row,col);

    printw("Press Ctrl + C to quit.");
    refresh();
    sleep(3);
    erase();

    PrintMovingObj(row,col);
    

    // move(row-2,0);
    // printw("press any key to exit...");
    // refresh();
    // getch();
    endwin();

    return 0;
}

void PrintMovingObj(int row,int col)
{
    int x = 10;
    int y = 10;
    move(y, x);
    printw("0");
    refresh();
    erase();
 
    MoveMaze(row, col,y,x);
    
}

void MoveMaze(int row,int col,int y,int x)
{
    int xdir = 0; 
    int ydir = 0;
    int xpos = x;
    int ypos = y;

    while(1){
    
    if (getchar() == ARROW && getchar() == ARROW2)
    {
        int nkey = getchar();
        switch (nkey)
        {
        case UP:
            ydir = -1, xdir = 0;
            break;

        case DOWN:
            ydir = +1, xdir = 0;
            break;

        case LEFT:
            ydir = 0, xdir = -1;
            break;

        case RIGHT:
            ydir = 0, xdir = +1;
            break;
        }
        xpos += xdir;
        ypos += ydir;
        move(ypos, xpos);
        printw("0");
        refresh();
        erase();
        
    }
    // when obj gets out of window
    if (ypos > row){
        ypos = ypos - row;
    }
    if (ypos < 0){
        ypos = ypos + row;
    }
    if (xpos > col){
        ypos = ypos - col;
    }
    if (xpos < 0){
        xpos = xpos + col;
    }

    }
}