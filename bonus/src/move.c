/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** put down
*/

#include "my.h"

int	move_down(tetris_t *tet, char **map)
{
	for (point_t *tmp = tet->list[tet->state]; tmp; tmp = tmp->next) {
		if (tmp->y + 1 > 19 || map[tmp->y + 1][tmp->x] != -1 )
			return (1);
	}
	for (point_t *tmp = tet->list[0]; tmp; tmp = tmp->next)
		tmp->y += 1;
	for (point_t *tmp = tet->list[1]; tmp; tmp = tmp->next)
		tmp->y += 1;
	for (point_t *tmp = tet->list[2]; tmp; tmp = tmp->next)
		tmp->y += 1;
	for (point_t *tmp = tet->list[3]; tmp; tmp = tmp->next)
		tmp->y += 1;
	return (0);
}

int	move_side(tetris_t *tet, char **map, int dir)
{
	for (point_t *tmp = tet->list[tet->state]; tmp; tmp = tmp->next) {
		if (tmp->x + dir > 9 || tmp->x + dir < 0
		|| map[tmp->y][tmp->x + dir] != -1)
			return (1);
	}
	for (point_t *tmp = tet->list[0]; tmp; tmp = tmp->next)
		tmp->x += dir;
	for (point_t *tmp = tet->list[1]; tmp; tmp = tmp->next)
		tmp->x += dir;
	for (point_t *tmp = tet->list[2]; tmp; tmp = tmp->next)
		tmp->x += dir;
	for (point_t *tmp = tet->list[3]; tmp; tmp = tmp->next)
		tmp->x += dir;
	return (0);
}

int	move_only_one_side(point_t *list, char **map)
{
	for (point_t *tmp = list; tmp; tmp = tmp->next) {
		if (tmp->x + 1 > 9) {
			return (1);
		}
		if (tmp->x + 1 < 0)
			return (1);
		if (map[tmp->y][tmp->x + 1] != -1)
			return (1);
	}
	for (point_t *tmp = list; tmp; tmp = tmp->next)
		tmp->x += 1;
	return (0);
}

int	move_only_one_down(point_t *list, char **map)
{
	for (point_t *tmp = list; tmp; tmp = tmp->next) {
		if (tmp->y + 1 > 19 || map[tmp->y + 1][tmp->x] != -1)
			return (1);
	}
	for (point_t *tmp = list; tmp; tmp = tmp->next)
		tmp->y += 1;
	return (0);
}
