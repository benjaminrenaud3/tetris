/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"
#include "printf.h"

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

back_t	*get_line(char *line, back_t **list, back_t *tmp)
{
	back_t *new = malloc(sizeof(*new));

	if (!new)
		return (tmp);
	new->line = line;
	new->next = NULL;
	if (tmp == NULL)
		*list = new;
	else
		tmp->next = new;
	return (new);
}

back_t	*get_back(void)
{
	int fd = open("back", O_RDONLY);
	back_t *list = NULL;
	back_t *tmp = NULL;
	char *line = NULL;

	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line) {
		tmp = get_line(line, &list, tmp);
		line = get_next_line(fd);
	}
	return (list);
}

int	main(void)
{
	int len = 0;
	save_t *list = NULL;
	back_t *back = get_back();
	int ret = 0;

	list = get_tetrimino(&len);
	srand(time(NULL));
	initscr();
	noecho();
	start_color();
	edit_color();
	curs_set(0);
	keypad(stdscr, TRUE);
	timeout(0);
	ret = start_game(list, len, back);
	endwin();
	my_printf("%d\n", ret);
	return (0);
}
