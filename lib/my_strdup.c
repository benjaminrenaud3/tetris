/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strdump
*/

#include "../include/my.h"

char	*my_strdup(char *str)
{
	char *new = malloc(sizeof(char) * (my_strlen(str) + 1));
	int i = 0;

	if (!new)
		return (NULL);
	for (; str && str[i]; i += 1)
		new[i] = str[i];
	new[i] = 0;
	return (new);
}
