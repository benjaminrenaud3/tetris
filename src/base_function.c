/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** base_fonction
*/

#include "my.h"

int cmp_c (char key, char c)
{
	if (key == c)
		return (0);
	else
		return (1);
}

int cmp(char *str, char *str2)
{
	int len = my_strlen(str);
	int cpt = 0;

	for (;str && str2 && str[cpt] != '\0' && str[cpt] == str2[cpt]; cpt++);
	if (cpt == len && str && str[cpt] == '\0' && str2 && str2[cpt] == '\0')
		return (0);
	return (1);
}

void fill_case(char *str, char *src)
{
	int cpt = 0;

	for (; str && src[cpt] != '\0'; cpt++)
		str[cpt] = src[cpt];
	str[cpt] = 0;
}
