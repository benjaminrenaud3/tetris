/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** bonus ai
*/

#include "my.h"
#include "printf.h"

move_t	*add_move(int rotate, int pos_x, double score, move_t *all)
{
	move_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->rotate = rotate;
	new->move = pos_x;
	new->score = score;
	new->next = all;
	return (new);
}

move_t	*test_next_piece(tetris_t *next, char **map, int pos, move_t *all)
{
	tetris_t *tmp = make_a_copy(next);
	tetris_t *tmp2 = make_a_copy(next);
	int j = 0;
	double score = 0;
	int rotate = (pos & 0x00ff0000) >> 16;

	pos = pos & 0x000000ff;
	for (int i = 0; i < 10;
	j += j == 3 ? -3 : 1, i += j == 0 ? 1 : 0) {
		reload_list(tmp->list[j], tmp2->list[j]);
		score = calc_score(tmp->list[j], map, i);
		if (score != 84)
			all = add_move(rotate, pos, score, all);
	}
	clear_old_piece(tmp);
	clear_old_piece(tmp2);
	return (all);
}

int	prepare_map(point_t *list, char **map, int i)
{
	for (int j = 0; j != i; j += 1) {
		if (move_only_one_side(list, map))
			return (84);
	}
	while (move_only_one_down(list, map) == 0);
	for (; list; list = list->next)
		map[list->y][list->x] = 10;
	return (0);
}

void	clear_list_on_map(point_t *list, char **map)
{
	for (; list; list = list->next)
		map[list->y][list->x] = -1;
}

void	do_the_best_move(tetris_t *tet, tetris_t *next, char **map)
{
	move_t *all = NULL;
	tetris_t *tmp = make_a_copy(tet);
	tetris_t *tmp2 = make_a_copy(tet);
	int j = 0;
	int fusion = 0;

	for (int i = 0; i < 10; j += j == 3 ? -3 : 1, i += j == 0 ? 1 : 0) {
		reload_list(tmp->list[j], tmp2->list[j]);
		if (prepare_map(tmp->list[j], map, i) == 84)
			continue;
		fusion = i | (j << 16);
		all = test_next_piece(next, map, fusion, all);
		clear_list_on_map(tmp->list[j], map);
	}
	make_move(all, tet, map);
	clear_old_piece(tmp);
	clear_old_piece(tmp2);
}
