/*
** EPITECH PROJECT, 2018
** debug
** File description:
** tetris
*/

#include "my.h"

struct simple_key sfunc[8];
struct double_key dfunc[9];

void fill_tab_start(char **tab)
{
	tab[0] = malloc(sizeof(char) * 2);
	fill_case(tab[0], "1");
	tab[1] = malloc(sizeof(char) * 5);
	fill_case(tab[1], "^EOD");
	tab[2] = malloc(sizeof(char) * 5);
	fill_case(tab[2], "^EOC");
	tab[3] = malloc(sizeof(char) * 5);
	fill_case(tab[3], "^EOA");
	tab[4] = malloc(sizeof(char) * 5);
	fill_case(tab[4], "^EOB");
	tab[5] = malloc(sizeof(char) * 2);
	fill_case(tab[5], "q");
	tab[6] = malloc(sizeof(char) * 2);
	fill_case(tab[6], " ");
	tab[7] = malloc(sizeof(char) * 6);
	fill_case(tab[7], "False");
	tab[8] = malloc(sizeof(char) * 6);
	fill_case(tab[8], "20,10");
}

char *take_key(char *src)
{
	int cpt = 0;
	int a = 0;
	char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

	for (; src[cpt] != '='; cpt++);
	cpt++;
	if (src[cpt] == '{') {
		cpt++;
		for (; src[cpt] != '}'; cpt++) {
			str[a] = src[cpt];
			a++;
		}
	} else {
		for (; src[cpt] != '\0'; cpt++) {
			str[a] = src[cpt];
			a++;
		}
	}
	str[a] = '\0';
	return (str);
}

void show_next(char **control, int tabcase, char **argv, int *ind)
{
	(void)argv;
	*ind += 1;
	control[tabcase] = "True";
}

char *recup_av_double_dash(char *src)
{
	int cpt = 0;
	char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

	while (src[cpt] != '=' && src[cpt] != '\0') {
		str[cpt] = src[cpt];
		cpt++;
	}
	if (src[cpt] == '=') {
		str[cpt] = '=';
		str[cpt + 1] = '\0';
	} else
		str[cpt] = '\0';
	return (str);
}
