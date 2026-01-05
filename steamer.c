#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>

void timer() {
	int hours, minutes, seconds, total;
	char *text = "Time remaining: ";
	int rows, cols;
	int len, startx, starty;

	printf("Hours: ");
	scanf("%d", &hours);
	printf("Minutes: ");
	scanf("%d", &minutes);
	printf("Seconds: ");
	scanf("%d", &seconds);

	total = hours * 3600 + minutes * 60 + seconds;

//	printf("\nTimer started for %02d:%02d:%02d\n", hours, minutes, seconds);

	initscr();
	cbreak();
	noecho();

	getmaxyx(stdscr, rows, cols);

	len = strlen(text);
	startx = (cols - len) / 2;
	starty = rows / 2;

	while (total > 0) {
		int h = total / 3600;
		int m = (total % 3600) / 60;
		int s = total % 60;
		curs_set(0);

		mvprintw(starty, startx, "%s%02d:%02d:%02d\n", text, h, m, s);

		mvprintw(starty + 2, (cols - strlen("CTRL+C to exit")) / 2, "CTRL+C to exit");
		refresh();

		sleep(1);
		total--;
	}
	endwin();
	printf("Time's up!\n");

}

int main() {
	printf("Welcome to steamer 1.0!\n");
	timer();
	return 0;
}
