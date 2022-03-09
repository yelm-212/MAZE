#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>


#define SIZE 19

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

// void PrintLine(int row);
// void PrintMovingObj(int row,int col);
void Move(int row,int col,int y,int x);
void LoadMaze(char num);
void MoveMaze(int* row, int* col);
int IsBlock(int i, int j);
int IsFinish(int i, int j);
void PrintMazeGame();

void Complete();

struct timeval start, end;
double res;

char maze[SIZE][SIZE];

int main(void)
{
    int row, col = 0;
    char level;
    
    signal(SIGINT, interruptHandler);
    setlocale(LC_ALL, "");
    initscr();
    curs_set(0);
    getmaxyx(stdscr,row,col);

    move(2,2);
    printw("미로 찾기 게임\n");
    move(3,2);
    printw("난이도를 선택하세요. (1, 2, 3) ");

    refresh();
    level = getchar();
    
    LoadMaze(level);
    PrintMazeGame();
    gettimeofday(&start, NULL); 
    

    // move(row-2,0);
    // printw("press any key to exit...");
    // refresh();
    // getch();
    // endwin();

    return 0;
}


void PrintMazeGame()
{
    for (int i = 0; i < SIZE; i++)
    {
        move(5, 5);
        for (int j = 0; j < SIZE; j++)
        {
            if (maze[i][j] == '1')
                printw("■");
            else if (maze[i][j] == 'y')
                printw("★");
            else if (maze[i][j] == '0')
                printw("□");
            else if (maze[i][j] == 'x')
                printw("●");
        }
        refresh();
    }
}

int IsBlock(int i, int j)
{
    if (maze[i][j] == '1' || maze[i][j] == 'y')
        return 1;
    else
        return 0;
}
int IsFinish(int i, int j)
{

    if (maze[i][j] == 'y')
        return 1;
    else
        return 0;
}

// void PrintMovingObj(int row,int col)
// {
//     int x = 5;
//     int y = 5;
//     move(y, x);
//     printw("●");
//     refresh();
//     erase();
 
//     Move(row, col,y,x);
    
// }

void Move(int row,int col,int y,int x)
{
    int xdir = 0; 
    int ydir = 0;
    int xpos = x;
    int ypos = y;

    while(1){
    
    PrintMazeGame();

    if (getchar() == ARROW && getchar() == ARROW2)
    {
        int nkey = getchar();
        switch (nkey)
        {
        case UP:
        if (!(IsBlock(row - 1, col)))
            {
            addstr(" ");
            ydir = -1, xdir = 0;
            }
        else if (IsFinish(row - 1, col))
        {
            
            PrintMazeGame();
            Complete();
        }
        break;

        case DOWN:
        if (!(IsBlock(row +1, col)))
            {
            addstr(" ");
            ydir = +1, xdir = 0;
            }
        else if (IsFinish(row + 1, col))
        {
            
            PrintMazeGame();
            Complete();
        }
            break;

        case LEFT:
        if (!(IsBlock(row , col-1)))
            {
            addstr(" ");
            ydir = 0, xdir = -1;
            }
        else if (IsFinish(row , col -1))
        {
            
            PrintMazeGame();
            Complete();
        }
            break;

        case RIGHT:
        if (!(IsBlock(row , col+1)))
            {
            addstr(" ");
            ydir = 0, xdir = -1;
            }
        else if (IsFinish(row , col +1))
        {
            
            PrintMazeGame();
            Complete();
        }
            ydir = 0, xdir = +1;
            break;
        }
        xpos += xdir;
        ypos += ydir;
        move(ypos, xpos);
        addstr("●");
        refresh();
        
    }
    // // when obj gets out of window
    // if (ypos > row){
    //     ypos = ypos - row;
    // }
    // if (ypos < 0){
    //     ypos = ypos + row;
    // }
    // if (xpos > col){
    //     xpos = xpos - col;
    // }
    // if (xpos < 0){
    //     xpos = xpos + col;
    // }

    // if(xpos == X_LINE){
    //     endwin();
    //     exit(0);
    // }

    }
}

void LoadMaze(char num)
{
    char path[20] = "./Maze";
    char numArr[2] = {num, '\0'};
    strcat(path, numArr);
    strcat(path, ".txt");

    char str_tmp[50] = { 0, };
    FILE* f = fopen(path, "r");
    if (f == NULL){
        printw("NULL");
        printw("\n%s\n", path);
        refresh();
    }

    for (int i = 0; i < SIZE; i++)
    {
        fgets(str_tmp, 50, f);
        char* ptr = strtok(str_tmp, "\t");
        for (int j = 0; j < SIZE; j++)
        {
            maze[i][j] = *ptr;
            ptr = strtok(NULL, "\t");
        }
    }
    fclose(f);
}

void Complete()
{
    gettimeofday(&end, NULL);
    res = ( end.tv_sec - start.tv_sec ) + ((double)( end.tv_usec - start.tv_usec ) / 1000000 );

    move(SIZE+8, 4);
    printw("Complete!\n");
    move(SIZE +10, 4);
    printw("경과시간 : %.2lf초", res);
    addstr("\npress any key to exit...");
    refresh();
    getch();
    exit(0);
}