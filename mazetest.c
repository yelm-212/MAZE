#include <stdio.h>
#include <string.h>
#define SIZE 19


int main(void) 
{
    char path[20] = "./Maze1.txt";
    char str_tmp[50] = { 0, };
    FILE* f = fopen(&path, "r");

    for (int i = 0; i < SIZE; i++)
    {
        fgets(str_tmp, 50, f);
        printf("%s", str_tmp);
    }
    fclose(f);

}