#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

void timer(int hours, int minutes, int seconds) {
	int total;
	char *text = "Time remaining: ";
	int rows, cols;
	int len, startx, starty;
    int ch;

	total = hours * 3600 + minutes * 60 + seconds;

	initscr();
	cbreak();
	noecho();
	curs_set(0);
    nodelay(stdscr, TRUE);

	getmaxyx(stdscr, rows, cols);

	len = strlen(text);
	startx = (cols - len - 17) / 2;
	starty = rows / 2;

	while (total > 0) {
		int h = total / 3600;
		int m = (total % 3600) / 60;
		int s = total % 60;

		mvprintw(starty, startx, "%s%02d:%02d:%02d\n", text, h, m, s);

		mvprintw(starty + 2, (cols - strlen("Press 'q' to exit")) / 2, "Press 'q' to exit");
		refresh();

		sleep(1);
		total--;
        ch = getch();
        if (ch == 'q') {
			curs_set(1);
            endwin();
            exit(EXIT_SUCCESS);
		}
        if (ch == ERR) {
        	refresh();
            napms(100);
        }
	}
	curs_set(1);
	endwin();
	printf("\nTime's up!\n");

}

int main() {
        int a, b, c;
	printf("Welcome to steamer 1.2!\n");

        printf("Hours: ");
	scanf("%d", &a);
	printf("Minutes: ");
	scanf("%d", &b);
	printf("Seconds: ");
	scanf("%d", &c);
	timer(a, b, c);
	return 0;
}
