/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** check_loose
*/

#include "my.h"

int	check_loose(game_t *game)
{
	for (int i = 0; i < game->x; i += 1) {
		if (game->map[0][i] != -1)
			return (0);
	}
	return (1);
}
