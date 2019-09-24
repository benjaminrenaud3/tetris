/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** sort_list
*/

#include "my.h"

int	is_sort(save_t *list)
{
	for (; list && list->next; list = list->next) {
		if (my_strcmp(my_strdup(list->name),
		my_strdup(list->next->name)) > 0)
			return (0);
	}
	return (1);
}

void	compare_node(save_t *tmp, save_t *tmp2, save_t *tmp3, save_t **list)
{
	if (my_strcmp(my_strdup(tmp->name), my_strdup(tmp2->name)) > 0) {
		tmp->next = tmp2->next;
		tmp2->next = tmp;
		if (tmp3)
			tmp3->next = tmp2;
		else
			*list = tmp2;
	}
}

save_t	*sort_list(save_t *list)
{
	save_t *tmp2 = NULL;

	while (is_sort(list) == 0) {
		for (save_t *tmp = list; tmp && tmp->next;
		tmp2 = tmp, tmp = tmp->next)
			compare_node(tmp, tmp->next, tmp2, &list);
		tmp2 = NULL;
	}
	return (list);
}
