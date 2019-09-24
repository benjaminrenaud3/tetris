/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** stat
*/

#include "my.h"

stat_t	init_stat(int level)
{
	stat_t stat;

	stat.time_start = time(NULL);
	stat.level = level;
	stat.line = 0;
	stat.score = 0;
	return (stat);
}

void	disp_score(int score, int line)
{
	int col = 22;

	do {
		mvaddch(line, col, (char)(score % 10 + 48));
		score /= 10;
		col -= 1;
	} while (score);
}

void	disp_timer(int sec)
{
	int min = sec / 60;

	sec %= 60;
	mvprintw(18, 4, "Timer : ");
	mvaddch(18, 22, (char)(sec % 10 + 48));
	mvaddch(18, 21, (char)(sec / 10 + 48));
	mvaddch(18, 20, ':');
	mvaddch(18, 19, (char)(min % 10 + 48));
	mvaddch(18, 18, (char)(min / 10 + 48));
}

void	disp_stat(stat_t stat)
{
	draw_edge(3, 12, 10, 7);
	disp_timer(time(NULL) - stat.time_start);
	mvprintw(16, 4, "Level : ");
	mvaddch(16, 22, (char)(stat.level % 10 + 48));
	mvaddch(16, 21, (char)(stat.level / 10 + 48));
	mvprintw(15, 4, "Lines : ");
	disp_score(stat.line, 15);
	mvprintw(13, 4, "Score : ");
	disp_score(stat.score, 13);
}
