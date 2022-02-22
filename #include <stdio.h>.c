#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void interruptHandler(int sig){
        printf("this program will be exited in 3 seconds..\n");
        sleep(3);
        endwin();
        exit(0);
}

void GotoXY(int x, int y)
{
		move(y,x);
}

void PrintMazeGame(row,col)
{
    for (int i = 0; i < row; i++)
    {
        move(i,col/2);
        for (int j = 0; j < row; j++)
        {
            printw("ㅁ");
        }
        refresh();
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


    while (1)
    {
        PrintMovingObj(row,col);
    }

    // move(row-2,0);
    // printw("press any key to exit...");
    // refresh();
    // getch();
    endwin();

    return 0;
}
