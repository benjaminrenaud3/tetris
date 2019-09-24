/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** init_game
*/

#include "my.h"

void	edit_color(void)
{
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_RED);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
	init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(4, COLOR_BLUE, COLOR_BLUE);
	init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(6, COLOR_CYAN, COLOR_CYAN);
	init_pair(7, COLOR_WHITE, COLOR_WHITE);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
}

game_t	*game_create(save_t *list, int len, char **control)
{
	game_t *game = malloc(sizeof(*game));
	int i = 0;

	if (!game)
		return (NULL);
	game->control = control;
	game->list = list;
	game->len = len;
	game->pause = -1;
	game->quit = 1;
	game->map = NULL;
	game->next = cmp(control[7], "False") == 0 ? 1 : 0;
	game->y = my_getnbr(control[8]);
	for (; control[8][i] != '*' && control[8][i] != ','; i += 1);
	game->x = my_getnbr(control[8] + i + 1);
	game->stat = init_stat(my_getnbr(control[0]));
	game->wait = 0.4;
	for (int i = 1; i < game->stat.level; i += 1)
		game->wait *= 0.9;
	return (game);
}

int	init_game(save_t *list, int len, char **control)
{
	game_t *game = NULL;

	srand(time(NULL));
	game = game_create(list, len, control);
	if (!game)
		return (84);
	initscr();
	noecho();
	start_color();
	edit_color();
	curs_set(0);
	keypad(stdscr, TRUE);
	timeout(0);
	start_game(game);
	endwin();
	return (1);
}
