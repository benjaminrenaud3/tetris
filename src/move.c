/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** put down
*/

#include "my.h"
#include "printf.h"

int	move_down(tetris_t *tet, game_t *game)
{
	for (point_t *tmp = tet->list[tet->state]; tmp; tmp = tmp->next) {
		if (tmp->y + 2 > game->y || game->map[tmp->y + 1][tmp->x] != -1)
			return (1);
	}
	if (game->pause == 1)
		return (1);
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

int	move_side(tetris_t *tet, game_t *game, int dir)
{
	for (point_t *tmp = tet->list[tet->state]; tmp; tmp = tmp->next) {
		if (tmp->x + dir > game->x || tmp->x + dir < 0
		|| game->map[tmp->y][tmp->x + dir] != -1)
			return (1);
	}
	if (game->pause == 1)
		return (1);
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
