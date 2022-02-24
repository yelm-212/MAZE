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

#define X_LINE 20

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

void PrintLine(int row);
void PrintMovingObj(int row,int col);
void Move(int row,int col,int y,int x);

int main(void)
{
    int row, col = 0;
    signal(SIGINT, interruptHandler);
    setlocale(LC_ALL, "");
    initscr();
    curs_set(0);
    getmaxyx(stdscr,row,col);

    printw("This program will end \n when Obj(0) reachs the line\n");
    refresh();
    sleep(3);
    erase();
    
    PrintLine(row);
    PrintMovingObj(row,col);
    

    // move(row-2,0);
    // printw("press any key to exit...");
    // refresh();
    // getch();
    endwin();

    return 0;
}


void PrintLine(int row)
{   
    for(int i=0;i<row;i++){
    move(i, X_LINE);
    addstr("I");
    }
    
}

void PrintMovingObj(int row,int col)
{
    int x = 5;
    int y = 5;
    move(y, x);
    printw("0");
    refresh();
    erase();
 
    Move(row, col,y,x);
    
}

void Move(int row,int col,int y,int x)
{
    int xdir = 0; 
    int ydir = 0;
    int xpos = x;
    int ypos = y;

    while(1){
    
    PrintLine(row);

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
        xpos = xpos - col;
    }
    if (xpos < 0){
        xpos = xpos + col;
    }

    if(xpos == X_LINE){
        endwin();
        exit(0);
    }

    }
}