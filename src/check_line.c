/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** check_line
*/

#include "my.h"

void	put_all_down(char **map, int line, int x)
{
	for (int i = line - 1; i >= 0; i -= 1) {
		for (int j = 0; j < x; j += 1) {
			map[i + 1][j] = map[i][j];
		}
	}
	for (int i = 0; i < x; i +=1)
		map[0][i] = -1;
}

int	check_this_line(int *line, char **map, int x)
{
	for (int i = 0; i < x; i += 1) {
		if (map[*line][i] == -1)
			return (0);
	}
	put_all_down(map, *line, x);
	*line += 1;
	return (1);
}

void	check_line_tet(game_t *game)
{
	static int nb = 0;
	float combo = 1;

	for (int i = game->y - 1; i >= 0; i -= 1) {
		if (check_this_line(&i, game->map, game->x)) {
			nb += 1;
			game->stat.line += 1;
			game->stat.score += 100. * combo;
			combo += 0.5;
		}
	}
	if (nb >= 10) {
		game->stat.level += 1;
		game->wait = 0.4;
		for (int i = 1; i < game->stat.level; i += 1)
			game->wait *= 0.9;
		nb %= 10;
	}
}
