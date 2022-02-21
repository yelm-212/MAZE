#include <ncurses.h>
#include <stdio.h>
#include <locale.h>

void GotoXY(int x, int y)
{
		move(y,x);
}

int main(void)
{
    int step;

    printf("층계의 개수를 입력하세요. \n");
    scanf("%d",&step);

    setlocale(LC_ALL, "");
	initscr();

    for (int i=0; i<step;i++){
        GotoXY(i,i);
        printw("ㄱ");
    }


	addstr("\npress any key to exit...");
    refresh();
    getch();


    endwin();
	// end curses mode
}