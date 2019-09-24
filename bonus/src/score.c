/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** ai score
*/

#include "my.h"
#include "printf.h"

double	get_aggregate_height(char **map)
{
	double height = 0;
	int j = 0;

	for (int i = 0; i < 10; i += 1) {
		for (j = 0; j < 20 && map[j][i] == -1; j += 1);
		height += 20 - j;
	}
	return (height);
}

double	get_completed_line(char **map)
{
	double line = 0;
	int tmp = 0;

	for (int i = 0; i < 20; i += 1) {
		for (int j = 0; j < 10; j += 1)
			tmp += map[i][j] == -1 ? 0 : 1;
		line += tmp == 10 ? 1 : 0;
		tmp = 0;
	}
	return (line);
}

double	get_hole(char **map)
{
	double hole = 0;

	for (int i = 2; i < 20; i += 1) {
		for (int j = 0; j < 10; j += 1)
			hole += map[i][j] == -1 && map[i - 1][j] != -1 ? 1 : 0;
	}
	return (hole);
}

double	get_bumpiness(char **map)
{
	double bumpiness = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int j = 0;

	for (int i = 0; i < 9; i += 1) {
		for (j = 0; j < 20 && map[j][i] == -1; j += 1);
		tmp1 = 20 - j;
		for (j = 0; j < 20 && map[j][i + 1] == -1; j += 1);
		tmp2 = 20 - j;
		bumpiness += tmp1 - tmp2 > 0 ? tmp1 - tmp2 : tmp2 - tmp1;
	}
	return (bumpiness);
}

double	calc_score(point_t *list, char **map, int pos)
{
	double aggregate_height = -0.510066;
	double completed_line = 0.760666;
	double hole = -0.35663;
	double bumpiness = -0.184483;

	for (int i = 0; i != pos; i += 1) {
		if (move_only_one_side(list, map) == 1)
			return (84);
	}
	while (move_only_one_down(list, map) == 0);
	for (point_t *tmp = list; tmp; tmp = tmp->next)
		map[tmp->y][tmp->x] = 10;
	aggregate_height *= get_aggregate_height(map);
	completed_line *= get_completed_line(map);
	hole *= get_hole(map);
	bumpiness *= get_bumpiness(map);
	for (point_t *tmp = list; tmp; tmp = tmp->next)
		map[tmp->y][tmp->x] = -1;
	return (aggregate_height + completed_line + hole + bumpiness);
}
