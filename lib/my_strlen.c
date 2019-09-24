/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strlen
*/

#include "../include/my.h"

int	my_strlen(char *str)
{
	int i = 0;

	for (; str != NULL && str[i]; i += 1);
	return (i);
}
