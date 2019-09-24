/*
** EPITECH PROJECT, 2018
** debug
** File description:
** tetris
*/

#include "my.h"

struct simple_key sfunc[8] = {
	{'L', &simple_fill_tab},
	{'l', &simple_fill_tab},
	{'r', &simple_fill_tab},
	{'t', &simple_fill_tab},
	{'d', &simple_fill_tab},
	{'q', &simple_fill_tab},
	{'p', &simple_fill_tab},
	{'w', &show_next}
};

struct double_key dfunc[9] = {
	{"--level=", &double_fill_tab},
	{"--key-left=", &double_fill_tab},
	{"--key-right=", &double_fill_tab},
	{"--key-turn=", &double_fill_tab},
	{"--key-drop=", &double_fill_tab},
	{"--key-quit=", &double_fill_tab},
	{"--key-pause=", &double_fill_tab},
	{"--without-next", &show_next},
	{"--map-size=", &double_fill_tab}
};

void simple_fill_tab(char **control, int tabcase, char **argv, int *ind)
{
	int len = 0;

	*ind += 1;
	if (argv[*ind] == NULL)
		exit (84);
	len = my_strlen(argv[*ind]);
	control[tabcase] = malloc(sizeof(char) * (len + 1));
	fill_case(control[tabcase], argv[*ind]);
	*ind += 1;
}

void double_fill_tab(char **control, int tabcase, char **argv, int *ind)
{
	char *after = take_key(argv[*ind]);
	control[tabcase] = malloc(sizeof(char) * (my_strlen(after) + 1));
	fill_case(control[tabcase], after);
}

int simple_dash(char **argv, char **control, int *ind, int disp)
{
	char c = argv[*ind][1];
	int cpt = 0;
	int ok = 0;

	if (c == 'D') {
		*ind += 1;
		disp = 1;
		ok = 1;
	}
	while (cpt < 8 && c != 'D') {
		if (cmp_c(sfunc[cpt].key, c) == 0) {
			sfunc[cpt].simple_fill(control, cpt, argv, ind);
			ok = 1;
		}
		cpt += 1;
	}
	if (ok == 0)
		exit(84);
	return (disp);
}

int double_dash(char **argv, char **control, int *ind, int disp)
{
	char *str = recup_av_double_dash(argv[*ind]);
	int cpt = 0;
	int ok = 0;

	if (cmp("--debug", str) == 0) {
		*ind += 1;
		disp = 1;
	}
	while (cpt < 9 && cmp("--debug", str) == 1) {
		if (cmp(dfunc[cpt].strkey, str) == 0) {
			dfunc[cpt].double_fill(control, cpt, argv, ind);
			ok = 1;
		}
		cpt += 1;
	}
	if (ok == 0)
		exit(84);
	*ind += 1;
	return (disp);
}

char **verif_option(int argc, char **argv, save_t *list, char **env)
{
	char **control = malloc(sizeof(char *) * 19);
	int ind = 1;
	int disp = 0;

	fill_tab_start(control);
	while (ind < argc) {
		if (argv[ind][0] == '-' && argv[ind][1] != '-' &&
		argv[ind][1] != 0)
			disp = simple_dash(argv, control, &ind, disp);
		else if (argv[ind][0] == '-' && argv[ind][1] == '-' &&
		argv[ind][2] != 0)
			disp = double_dash(argv, control, &ind, disp);
		else
			exit(84);

	}
	if (disp == 1)
		display_debugmod(control, list, env);
	return (control);
}
