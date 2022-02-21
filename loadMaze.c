#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <locale.h>
#define SIZE 19


void LoadMaze(char num);
char maze[SIZE][SIZE];

int main(void)
{
    setlocale(LC_ALL, "");
    initscr();
    char level;
    printw("난이도를 선택하세요. (1, 2, 3) ");
    refresh();
    level = getchar();

    LoadMaze(level);

    printw("\n");


    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printw("%c ", maze[i][j]);
        }
        printw("\n");
    }
    refresh();

    addstr("\npress any key to exit...");
    refresh();
    getch();
    endwin();
}

void LoadMaze(char num)
{
    char path[20] = "./Maze";
    char numArr[2] = {num, '\0'};
    strcat(path, numArr);
    strcat(path, ".txt");

    char str_tmp[50] = { 0, };
    FILE* f = fopen(path, "r");
    for (int i = 0; i < SIZE; i++)
        {
            fgets(str_tmp, 49, f);
            char* ptr = strtok(str_tmp, "\t");
            for (int j = 0; j < SIZE; j++)
            {
                maze[i][j] = *ptr;
                ptr = strtok(NULL, "\t");
            }
        }

    fclose(f);
}