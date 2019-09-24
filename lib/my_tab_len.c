/*
** EPITECH PROJECT, 2018
** my_tab_len
** File description:
** lib
*/

#include "../include/my.h"

int	my_tab_len(char **tab)
{
	int i = 0;

	for (;tab && tab[i]; i += 1);
	return (i);
}
