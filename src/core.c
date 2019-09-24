/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** core
*/

#include "my.h"
#include "printf.h"

int	check_rotation(tetris_t *tet, game_t *game, int turn)
{
	point_t *tmp = NULL;
	int new = (tet->state + 1) % 4;

	(void)turn;
	if (game->pause == 1)
		return (tet->state);
	for (tmp = tet->list[new]; tmp; tmp = tmp->next) {
		if (tmp->x < 0 || tmp->x > game->x - 1|| tmp->y > game->y - 1)
			return (tet->state);
		if (game->map[tmp->y][tmp->x] != -1)
			return (tet->state);
	}
	tet->state = new;
	return (new);
}

tetris_t	*change_piece(tetris_t *tet, game_t *game)
{
	add_piece_to_map(tet->list[tet->state], game->map);
	clear_old_piece(tet);
	return (create_new_piece(game));
}

char	**init_map(int y, int x)
{
	char **map = malloc(sizeof(char*) * y);

	if (!map)
		exit(84);
	for (int i = 0; i < y; i += 1) {
		map[i] = malloc(sizeof(char) * x);
		if (!map[i])
			exit(84);
		for (int j = 0; j != x; j += 1)
			map[i][j] = -1;
	}
	return (map);
}

int	start_game(game_t *game)
{
	tetris_t *now = create_new_piece(game);
	tetris_t *next = create_new_piece(game);
	tetris_t *tmp = NULL;

	game->map = init_map(game->y, game->x);
	while (check_loose(game) && game->quit) {
		if (game->pause == -1 && my_clock(game->wait)
		&& move_down(now, game)) {
			tmp = next;
			next = change_piece(now, game);
			now = tmp;
			check_line_tet(game);
		}
		draw(now->list[now->state], game, next->list[next->state]);
		attron(COLOR_PAIR(8));
		disp_stat(game->stat);
		refresh();
		get_event(now, game);
	}
	return (0);
}
