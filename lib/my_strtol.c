/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strtol
*/

#include "../include/printf.h"

int	my_strtol(char **tmp)
{
	int i = -1;
	int nb = 0;
	char *str = *tmp;

	while (str && str[++i] && (str[i] == ' ' || str[i] == '\t'));
	while (str && str[i] && str[i] >= '0' && str[i] <= '9') {
		nb += str[i] - 48;
		i += 1;
	}
	str += i;
	*tmp = str;
	return (nb);
}
