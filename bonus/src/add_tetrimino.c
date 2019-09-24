/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** add_tetrimino
*/

#include "my.h"
#include "printf.h"

char	**get_next_tab(char **tab)
{
	int y = my_strlen(tab[0]);
	int x = 0;
	char **new = NULL;

	for (; tab[x]; x += 1);
	new = malloc(sizeof(char*) * (y + 1));
	if (!new)
		return (NULL);
	for (int i = 0; i < y; i += 1) {
		new[i] = malloc(sizeof(char) * (x + 1));
		if (!new[i])
			return (NULL);
		new[i][x] = 0;
	}
	new[y] = NULL;
	for (int i = 0; tab[i]; i += 1) {
		for (int j = 0; tab[i][j]; j += 1)
			new[j][x - i - 1] = tab[i][j];
	}
	return (new);
}

save_t	*add_tetrimino(char **tab, save_t *list, int c)
{
	save_t *new = malloc(sizeof(*new));

	if (!new)
		return (list);
	new->tab1 = tab;
	new->tab2 = get_next_tab(new->tab1);
	if (!new->tab2)
		return (list);
	new->tab3 = get_next_tab(new->tab2);
	if (!new->tab3)
		return (list);
	new->tab4 = get_next_tab(new->tab3);
	if (!new->tab4)
		return (list);
	new->color = c;
	new->next = list;
	return (new);
}

char	*change_line(char *old, int w, int min)
{
	char *new = malloc(sizeof(char) * (w + 1));
	int i = 0;

	if (!new)
		return (NULL);
	for (i = 0; i < w && old[i + min]; i += 1)
		new[i] = old[i + min];
	for (; i < w; i += 1)
		new[i] = ' ';
	new[w] = 0;
	free(old);
	return (new);
}
