#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>

#define SIZE 19
#define XP 40
#define YP 5
#define LEFT 68
#define RIGHT 67
#define UP 65
#define DOWN 66
#define ARROW 27
#define ARROW2 91


void LoadMaze(char num);
void GotoXY(int x, int y);
void PrintMazeGame();
void MoveMaze(int* row, int* col);
int IsBlock(int i, int j);
int IsFinish(int i, int j);

char maze[SIZE][SIZE];

int main(void)
{
    setlocale(LC_ALL, "");
    initscr();
    curs_set(0);

    int row = 2, col = 1;
    char level;
    GotoXY(XP, YP - 3);
    printw("미로 찾기 게임\n");
    refresh();

    GotoXY(XP, YP - 2);
    printw("난이도를 선택하세요. (1, 2, 3) ");
    refresh();
    level = getchar();

    LoadMaze(level);

    while (1)
    {
        PrintMazeGame();
        MoveMaze(&row, &col);
    }

    addstr("\npress any key to exit...");
    refresh();
    getch();
    endwin();
}

void MoveMaze(int* row, int* col)
{
    if (getchar() == ARROW && getchar() == ARROW2)
    {
        int nkey = getchar();
        switch (nkey)
        {
        case UP:
            if (!(IsBlock(*row - 1, *col)))
            {
                maze[*row][*col] = '0';
                maze[*row - 1][*col] = 'x';
                *row -= 1;
            }
            else if (IsFinish(*row - 1, *col))
            {
                exit(0);
            }
            break;

        case DOWN:
            if (!(IsBlock(*row + 1, *col)))
            {
                maze[*row][*col] = '0';
                maze[*row + 1][*col] = 'x';
                *row += 1;
            }
            else if (IsFinish(*row + 1, *col))
            {
                exit(0);
            }
            break;

        case LEFT:
            if (!(IsBlock(*row, *col - 1)))
            {
                maze[*row][*col] = '0';
                maze[*row][*col - 1] = 'x';
                *col -= 1;
            }
            else if (IsFinish(*row, *col - 1))
            {
                exit(0);
            }
            break;

        case RIGHT:
            if (!(IsBlock(*row, *col + 1)))
            {
                maze[*row][*col] = '0';
                maze[*row][*col + 1] = 'x';
                *col += 1;
            }
            else if (IsFinish(*row, *col + 1))
            {
                exit(0);
            }
            break;
        }
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
void PrintMazeGame()
{
    for (int i = 0; i < SIZE; i++)
    {
        GotoXY(XP, YP + i);
        for (int j = 0; j < SIZE; j++)
        {
            if (maze[i][j] == '1')
                printw("■");
            else if (maze[i][j] == 'y')
                printw("★");
            else if (maze[i][j] == '0')
                printw("□");
            else
                printw("●");
        }
        refresh();
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
void GotoXY(int x, int y)
{
		move(y,x);
}