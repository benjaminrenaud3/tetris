/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** do_the_best_move
*/

#include "my.h"

point_t	*copy_list(point_t *list)
{
	point_t *new = NULL;

	for (; list; list = list->next)
		new = add_to_list(list->x, list->y, list->color, new);
	return (new);
}

tetris_t	*make_a_copy(tetris_t *tet)
{
	tetris_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->list[0] = copy_list(tet->list[0]);
	new->list[1] = copy_list(tet->list[1]);
	new->list[2] = copy_list(tet->list[2]);
	new->list[3] = copy_list(tet->list[3]);
	new->state = 0;
	return (new);
}
