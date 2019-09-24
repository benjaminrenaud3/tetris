/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** get_control
*/

#include "my.h"
#include "printf.h"

void nbr_tetrimino(save_t *list)
{
	int i = 0;

	for (; list; i += 1, list = list->next);
	my_printf("Tetriminos : %d\n", i);
}

int verif_double(char **control, char *str)
{
	int verif = 0;

	for (int cpt = 0; cpt != 9; cpt++) {
		if (cmp(str, control[cpt]) == 0)
			verif++;
		if (verif >= 2)
			return (1);
	}
	return (0);
}

int verif_nbr(char *str)
{
	int len;
	int cpt = 0;
	int virg = 0;

	if (str[0] == '-' || str[0] == 0)
		return (1);
	for (len = 0; str[len] != '\0'; len++);
	for (; (str[cpt] <= '9' && str[cpt] >= '0') ||
	(str[cpt] == ',' && virg == 0); cpt++) {
		if (str[cpt] == ',')
			virg++;
	}
	if (len != cpt)
		return (1);
	return (0);
}

void verify_and_change_size(char *str)
{
	int cpt = 0;
	int cpt2 = 0;
	int len = 0;

	if (verif_nbr(str) == 1)
		exit(84);
	for (; str[len] && str[len] != ','; len++);
	cpt = nbr_maker(str, 0);
	cpt2 = nbr_maker(str, len + 1);
	if (cpt < 8 || cpt > 50 || cpt2 < 10 || cpt2 > 50)
		exit(84);
	str[len] = '*';
}

void verify_level(char *str)
{
	int len = 0;
	int cpt = 0;
	int lvl = 0;

	lvl = nbr_maker(str, 0);
	for (len = 0; str[len] != '\0'; len++);
	for (cpt = 0; str[cpt] <= '9' && str[cpt] >= '0'; cpt++);
	if (len != cpt || lvl <= 0)
		exit(84);
}
