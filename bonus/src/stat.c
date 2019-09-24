/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** stat
*/

#include "my.h"

stat_t	init_stat(void)
{
	stat_t stat;

	stat.time_start = time(NULL);
	stat.level = 1;
	stat.line = 0;
	stat.score = 0;
	stat.highscore = 0;
	return (stat);
}

void	disp_score(int score, int line, int col)
{
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
	disp_score(sec, 18, 22);
	mvaddch(18, 20, ':');
	disp_score(min, 18, 19);
}

void	disp_stat(stat_t stat)
{
	attron(COLOR_PAIR(8));
	disp_timer(time(NULL) - stat.time_start);
	disp_score(stat.level, 16, 22);
	disp_score(stat.line, 15, 22);
	disp_score(stat.highscore, 12, 22);
	disp_score(stat.score, 13, 22);
	refresh();
}
