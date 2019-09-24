/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** draw
*/

#include "my.h"
#include "printf.h"

void	draw_edge(int x, int y, int size_x, int size_y)
{
	attron(COLOR_PAIR(8));
	mvaddch(y - 1, x - 2, '/');
	mvaddch(y - 1, x + size_x * 2 + 2, '\\');
	for (int i = -1; i <= size_x * 2; i += 1)
		mvaddch(y - 1, x + i, '-');
	for (int i = 0; i < size_y; i += 1) {
		mvaddch(y + i, x - 2, '|');
		mvaddch(y + i, x + size_x * 2 + 2, '|');
	}
	mvaddch(y + size_y, x - 2, '\\');
	mvaddch(y + size_y, x + size_x * 2 + 2, '/');
	for (int i = -1; i <= size_x * 2; i += 1)
		mvaddch(y + size_y, x + i, '-');
	attroff(COLOR_PAIR(8));
}

void	add_piece_to_map(point_t *list, char **map)
{
	for (; list; list = list->next)
		map[list->y][list->x] = list->color;
}

void	draw_point(point_t *list, int x, int y)
{
	for (;list; list = list->next) {
		attron(COLOR_PAIR(list->color));
		mvaddch(list->y + y, list->x * 2 + x, '*');
		mvaddch(list->y + y, list->x * 2 + x + 1, '*');
		attroff(COLOR_PAIR(list->color));
	}
}

void	add_line(char *map, int i, int x)
{
	for (int j = 0; j < x; j += 1) {
		if (map[j] == -1)
			continue;
		attron(COLOR_PAIR((int)map[j]));
		mvaddch(i + 2, (2 * j) + 35, '*');
		mvaddch(i + 2, (2 * j) + 36, '*');
		attroff(COLOR_PAIR((int)map[j]));
	}
}

void    draw(point_t *list, game_t *game, point_t *next)
{
	clear();
	draw_edge(35, 2, game->x, game->y);
	draw_point(list, 35, 2);
	for (int i = 0; i < game->y; i += 1) {
		add_line(game->map[i], i, game->x);
	}
	if (game->next) {
		draw_edge(35 + game->x * 2 + 7, 2, 4, 5);
		draw_point(next, 35 + game->x + 10, 2);
	}
}
