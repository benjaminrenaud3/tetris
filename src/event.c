/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** event
*/

#include "my.h"
#include "printf.h"

char	*add_str_to_str(char *input, int key)
{
	char *tmp = NULL;

	switch (key) {
	case 261:
		tmp = my_strcat(input, "^EOC");
		break;
	case 260:
		tmp = my_strcat(input, "^EOD");
		break;
	case 259:
		tmp = my_strcat(input, "^EOA");
		break;
	case 258:
		tmp = my_strcat(input, "^EOB");
		break;
	}
	if (input)
		free(input);
	return (tmp);
}

char	*add_ch_to_str(char *input, int key)
{
	char tmp[2] = {(char)key, 0};
	char *tmp2;

	tmp2 = my_strcat(input, tmp);
	if (input)
		free(input);
	return (tmp2);
}

char	*check_futur_event(char **control, char *input)
{
	int i = 0;
	char *tmp = input;

	if (tmp == NULL)
		return (NULL);
	for (; i < 7 && cmp_begin(tmp, control[i]); i += 1);
	while (i == 7 && *tmp) {
		tmp += 1;
		for (i = 0; i < 7 && cmp_begin(tmp, control[i]); i += 1);
	}
	tmp = my_strdup(tmp);
	free(input);
	return (tmp);
}

int	do_event(char **input, tetris_t *tet, game_t *game)
{
	int i = 1;

	*input = check_futur_event(game->control, *input);
	for (; i < 7 && cmp(game->control[i], *input); i += 1);
	switch (i) {
	case 1:
		return (move_side(tet, game, -1));
	case 2:
		return (move_side(tet, game, 1));
	case 3:
		return (check_rotation(tet, game, 1));
	case 4:
		return (move_down(tet, game));
	}
	game->pause = i == 6 ? game->pause * -1 : game->pause;
	game->quit = i == 5 ? 0 : 1;
	if (i == 6 || i == 5)
		return (0);
	return (-1);
}

void	get_event(tetris_t *tet, game_t *game)
{
	static char *input = NULL;
	int key= wgetch(stdscr);

	if (key == ERR)
		return;
	if (key > 255)
		input = add_str_to_str(input, key);
	else
		input = add_ch_to_str(input, key);
	if (do_event(&input, tet, game) != -1) {
		if (!input)
			return;
		free(input);
		input = 0;
	}
}
