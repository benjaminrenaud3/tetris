/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** check_line
*/

#include "my.h"

void	put_all_down(char **map, int line)
{
	for (int i = line - 1; i >= 0; i -= 1) {
		for (int j = 0; j < 10; j += 1) {
			map[i + 1][j] = map[i][j];
		}
	}
	for (int i = 0; i < 10; i +=1)
		map[0][i] = -1;
}

int	check_this_line(int *line, char **map)
{
	for (int i = 0; i < 10; i += 1) {
		if (map[*line][i] == -1)
			return (0);
	}
	put_all_down(map, *line);
	*line += 1;
	return (1);
}

void	check_line_tet(char **map, stat_t *stat)
{
	static int nb = 0;
	float combo = 1;

	for (int i = 19; i >= 0; i -= 1) {
		if (check_this_line(&i, map)) {
			nb += 1;
			stat->line += 1;
			stat->score += 100. * combo;
			combo += 0.5;
		}
	}
	if (nb >= 10) {
		stat->level += 1;
		nb %= 10;
	}
}
