/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** create a new piece
*/

#include "my.h"
#include "printf.h"

void	clear_old_piece(tetris_t *tet)
{
	for (int i = 0; i != 4; i += 1) {
		for (point_t *tmp = tet->list[i]->next; tmp; tmp = tmp->next) {
			free(tet->list[i]);
			tet->list[i] = tmp;
		}
		free(tet->list[i]);
	}
	free(tet);
}

point_t *add_to_list(int x, int y, int color, point_t *list)
{
	point_t *new = malloc(sizeof(*new));

	if (!new)
		return (list);
	new->x = x;
	new->y = y;
	new->color = color;
	new->next = list;
	return (new);
}

point_t	*create_list_from_tab(char **tab, int color, int rd)
{
	point_t *list = NULL;

	for (int i = 0; tab[i]; i += 1) {
		for (int j = 0; tab[i][j]; j += 1) {
			list = tab[i][j] == '*' ?
			add_to_list(j + rd, i, color, list) : list;
		}
	}
	return (list);
}

tetris_t	*create_new_piece(game_t *game)
{
	tetris_t *new = malloc(sizeof(*new));
	save_t *list = game->list;
	int rd = game->x / 2 - 1;

	if (!new)
		return (NULL);
	for (unsigned int i = rand() % game->len + 1; --i > 0;
	list = list->next);
	new->list[0] = create_list_from_tab(list->tab1, list->color, rd);
	new->list[1] = create_list_from_tab(list->tab2, list->color, rd);
	new->list[2] = create_list_from_tab(list->tab3, list->color, rd);
	new->list[3] = create_list_from_tab(list->tab4, list->color, rd);
	new->state = rand() % 4;
	return (new);
}
