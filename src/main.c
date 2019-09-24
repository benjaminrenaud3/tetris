/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"
#include "printf.h"

void	print_list(save_t *list)
{
	for (; list; list = list->next) {
		if (list->tab1 == NULL) {
			my_printf("Tetriminos : Name %s : Error\n", list->name);
			continue;
		}
		my_printf("Tetriminos : ");
		my_printf("Name %s : Size %d*", list->name, list->x);
		my_printf("%d : Color %d :\n", list->y, list->color);
		for (int i = 0; list->tab1[i]; i += 1)
			my_printf("%s\n", list->tab1[i]);
	}
}

char **verify_end(char *src, char **tab, char *str, char *tetri_verse)
{
	int cpt = 0;

	for (; src[cpt] != '\0' && src[cpt] != '.'; cpt++);
	if (my_cmp(str, tetri_verse) == 0)
		src[cpt] = '\0';
	else
		return (NULL);
	return (tab);
}

void suppr_end(save_t *list)
{
	int len = 0;
	int cpt = 0;
	char *tetri_verse = "onimirtet";
	char *end_name;

	for (; list; list = list->next) {
		cpt = 0;
		len = my_strlen(list->name);
		end_name = malloc(sizeof(char) * (len + 1));
		len--;
		for (; len >= 0 && list->name[len] != '.'; len--) {
			end_name[cpt] = list->name[len];
			cpt++;
		}
		end_name[cpt] = '\0';
		list->tab1 = verify_end(list->name,
		list->tab1, end_name, tetri_verse);
	}
}

save_t	*suppr_error(save_t *list, int *len)
{
	save_t *begin = list;
	save_t *tmp = list;

	for (; begin && begin->tab1 == NULL; begin = tmp) {
		tmp = tmp->next;
		free(begin);
		*len -= 1;
	}
	for (list = begin; list; tmp = list, list = list->next) {
		if (list->tab1 == NULL) {
			tmp->next = list->next;
			free(list);
			list = tmp;
			*len -= 1;
		}
	}
	return (begin);
}

int	main(int ac, char **av, char **env)
{
	int len = 0;
	save_t *list = NULL;
	char **control = NULL;

	list = get_tetrimino(&len);
	if (list == NULL)
		return (84);
	list = sort_list(list);
	suppr_end(list);
	control = get_control(ac, av, list, env);
	if (control == NULL)
		return (0);
	list = suppr_error(list, &len);
	if (list == NULL)
		return (84);
	return (init_game(list, len, control));
}
