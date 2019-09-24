/*
** EPITECH PROJECT, 2018
** lib
** File description:
** tetris
*/

#include "../include/my.h"

void	my_str_lower_case(char *str)
{
	for (int i = 0; str[i]; i += 1) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}

int	my_cmp(char *str, char *str2)
{
	int len = 0;
	int cpt = 0;

	for (;str[len] != '\0'; len++);
	for (;str[cpt] != '\0' && str[cpt] == str2[cpt]; cpt++);
	if (cpt == len && str[cpt] == '\0' && str2[cpt] == '\0')
		return (0);
	return (1);
}

int	my_strcmp(char *s1, char *s2)
{
	int i = 0;

	my_str_lower_case(s1);
	my_str_lower_case(s2);
	for (i = 0; s1[i]; i += 1) {
		if (s1[i] != s2[i]) {
			return (s1[i] - s2[i]);
		}
	}
	free(s1);
	if (s2[i]) {
		free(s2);
		return (-1);
	}
	free(s2);
	return (0);
}
