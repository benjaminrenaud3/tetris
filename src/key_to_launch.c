/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** get_control
*/

#include "my.h"
#include "printf.h"
#include <termios.h>
#include <term.h>

int cmp_begin(char *str, char *str2)
{
	int len = my_strlen(str);
	int cpt = 0;

	for (;str && str2 && str[cpt] != '\0' && str[cpt] == str2[cpt]; cpt++);
	if (cpt == len)
		return (0);
	return (1);
}

char *my_getenv(char *str, char **env)
{
	int cpt = 0;

	for (; env[cpt] && cmp_begin(str, env[cpt]) == 1; cpt++);
	if (!env[cpt])
		return (NULL);
	return (my_strdup(env[cpt] + my_strlen(str) + 1));
}

int reset_term(struct termios term)
{
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}

int waiting_keys(char **env)
{
	char *name_term = NULL;
	char buffer;
	struct termios term;

	name_term = my_getenv("TERM", env);
	if (!name_term)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	read(0, &buffer, 1);
	reset_term(term);
	return (0);
}
