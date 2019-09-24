/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** core
*/

#include "my.h"
#include "printf.h"

int	check_rotation(tetris_t *tet, char **map, int turn)
{
	point_t *tmp = NULL;
	int new = (tet->state + turn < 0 ? 3 : tet->state + turn) % 4;

	for (tmp = tet->list[new]; tmp; tmp = tmp->next) {
		if (tmp->x < 0 || tmp->x > 9 || tmp->y > 19)
			return (tet->state);
		if (map[tmp->y][tmp->x] != -1)
			return (tet->state);
	}
	return (new);
}

tetris_t	*change_piece(tetris_t *tet, char **map, save_t *list, int len)
{
	add_piece_to_map(tet->list[tet->state], map);
	clear_old_piece(tet);
	return (create_new_piece(list, len));
}

char	**init_map(void)
{
	char **map = malloc(sizeof(char*) * 20);

	if (!map)
		exit(84);
	for (int i = 0; i < 20; i += 1) {
		map[i] = malloc(sizeof(char) * 10);
		if (!map[i])
			exit(84);
		for (int j = 0; j != 10; j += 1)
			map[i][j] = -1;
	}
	return (map);
}

int	start_game(save_t *list, int len, back_t *back)
{
	char **map = init_map();
	tetris_t *now = create_new_piece(list, len);
	tetris_t *next = create_new_piece(list, len);
	tetris_t *tmp = NULL;
	stat_t stat = init_stat();
	double wait = 0.01;

	do_the_best_move(now, next, map);
	while (check_loose(map)) {
		if (my_clock(wait) && move_down(now, map)) {
			tmp = next;
			next = change_piece(now, map, list, len);
			now = tmp;
			check_line_tet(map, &stat);
			do_the_best_move(now, next, map);
		}
		draw(now->list[now->state], map, back, next->list[next->state]);
		disp_stat(stat);
	}
	return (stat.line);
}
