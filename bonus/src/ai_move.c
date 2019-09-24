/*
** EPITECH PROJECT, 2018
** ai_move
** File description:
** tetris
*/

#include "my.h"

void	reload_list(point_t *tmp1, point_t *tmp2)
{
	for (;tmp1; tmp1 = tmp1->next, tmp2 = tmp2->next) {
		tmp1->x = tmp2->x;
		tmp1->y = tmp2->y;
	}
}

void	clear_move(move_t *all)
{
	for (move_t *tmp = all->next; tmp; all = tmp, tmp = tmp->next)
		free(all);
	free(all);
}

int	is_another(move_t *all)
{
	int save = all->score;

	for (; all; all = all->next) {
		if (all->score == save && rand() % 2 == 0)
			return (1);
	}
	return (0);
}

move_t	*find_the_best_move(move_t *all)
{
	double tmp2 = -1000;

	for (move_t *tmp = all; tmp; tmp = tmp->next)
		tmp2 = tmp->score > tmp2 ? tmp->score : tmp2;
	for (; all && all->score != tmp2; all = all->next);
	return (all);
}

void	make_move(move_t *all, tetris_t *tet, char **map)
{
	move_t *tmp = find_the_best_move(all);

	if (!tmp)
		return;
	tet->state = tmp->rotate;
	for (int i = 0; i < tmp->move; i += 1)
		move_side(tet, map, 1);
	clear_move(all);
}
