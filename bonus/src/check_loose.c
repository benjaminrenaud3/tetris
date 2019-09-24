/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** check_loose
*/

#include "my.h"

int	check_loose(char **map)
{
	for (int i = 0; i < 10; i += 1) {
		if (map[0][i] != -1)
			return (0);
	}
	return (1);
}
