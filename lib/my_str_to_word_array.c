/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** str to word array
*/

#include "../include/my.h"

int     count_arg(char *str, char c)
{
	int nbr = 0;
	int i = 0;
	int a = 1;

	while (str[i] == c)
		i += 1;
	while (str[i]) {
		while (str[i] && ((str[i] != c &&
			str[i] != '\t') || (a == -1 && str[i]))) {
			a *= (str[i] == 34) ? -1 : 1;
			i += 1;
		}
		nbr += 1;
		while (str[i] == c || str[i] == '\t')
			i += 1;
	}
	return (nbr);
}

char	*next_word(char *str, char **ptr, char c, int opt)
{
	int i = -1;
	char *word = NULL;
	int a = 1;
	int j = -1;

	while (str[++i] && ((str[i] != c && str[i] != '\t') || a == -1))
		a *= (str[i] == 34) ? -1 : 1;
	if ((word = malloc(sizeof(char) * (i + 1))) == NULL)
		exit(84);
	i = -1;
	while (str[++i] && ((str[i] != c && str[i] != '\t') || a == -1)) {
		a *= (str[i] == 34) ? -1 : 1;
		word[++j] = str[i];
		j -= (str[i] == 34 && opt == 1) ? 1 : 0;
	}
	word[++j] = 0;
	while (str[i] && str[++i] && (str[i] == c || str[i] == '\t'));
	*ptr += i;
	return (word);
}

char	**my_str_to_word_array(char *str, char c, int opt)
{
	int i = 0;
	char **arg = malloc(sizeof(char*) * (count_arg(str, c) + 1));

	if (arg == NULL)
		exit(84);
	while (str && (*str == c || *str == '\t'))
		str += 1;
	while (*str) {
		arg[i] = next_word(str, &str, c, opt);
		i += 1;
	}
	arg[i] = NULL;
	return (arg);
}
