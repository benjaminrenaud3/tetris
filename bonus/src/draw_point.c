/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** draw
*/

#include "my.h"
#include "printf.h"

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
	}
}

void	add_line(char *map, int i)
{
	for (int j = 0; j < 10; j += 1) {
		if (map[j] == -1)
			continue;
		attron(COLOR_PAIR((int)map[j]));
		mvaddch(i + 2, (2 * j) + 35, '*');
		mvaddch(i + 2, (2 * j) + 36, '*');
	}
}

void	draw(point_t *list, char **map, back_t *back, point_t *next)
{
	clear();
	attron(COLOR_PAIR(8));
	for (; back; back = back->next) {
		printw(back->line);
		addch('\n');
	}
	draw_point(list, 35, 2);
	for (int i = 0; i < 20; i += 1) {
		add_line(map[i], i);
	}
	draw_point(next, 61, 2);
}
