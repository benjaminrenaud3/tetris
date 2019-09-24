/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetrimino
*/

#include "my.h"
#include "printf.h"

int	get_info(char *line, int *h, int *w, int *c)
{
	char *tmp = line;

	if (!line)
		return (-1);
	*w = my_strtol(&line);
	*h = my_strtol(&line);
	*c = my_strtol(&line);
	free(tmp);
	if (*c < 0 || *c > 7 || *w < 1 || *h < 1)
		return (-1);
	return (0);
}

int	get_min_and_max(char **tab, int w, int *min)
{
	int max = 0;
	int nb = 0;

	for (int i = 0; tab[i]; i += 1) {
		for (int j = 0; tab[i][j]; j += 1) {
			*min = tab[i][j] == '*' && (j < *min ||
			*min == -1) ? j : *min;
			max = tab[i][j] == '*' && j > max ? j : max;
			nb = tab[i][j] != '*' && tab[i][j] != ' ' ? -1 : nb;
			nb += tab[i][j] == '*' && nb != -1 ? 1 : 0;
		}
		if (nb <= 0)
			return (-1);
		nb = 0;
	}
	if (max - *min >= w)
		return (-1);
	return (0);
}

save_t	*check_tetrimino(char **tab, int w, save_t *list, char *name)
{
	int min = -1;

	if (get_min_and_max(tab, w & 0x00ffffff , &min) == -1)
		return (list);
	for (int i = 0; tab[i]; i += 1)
		tab[i] = change_line(tab[i], w & 0x00ffffff, min);
	list = add_tetrimino(tab, list, (w & 0xff000000) >> 24, name);
	return (list);
}

save_t	*next_tetrimino(char *path, save_t *list, char *name)
{
	int fd = open(path, O_RDONLY);
	char **tab = NULL;
	int h = 0;
	int w = 0;
	int c = 0;

	if (fd == -1 || get_info(get_next_line(fd), &h, &w, &c) == -1)
		return (list);
	tab = malloc(sizeof(char*) * (h + 1));
	if (!tab)
		return (list);
	for (int i = 0; i < h; i += 1) {
		tab[i] = get_next_line(fd);
		if (!tab[i])
			return (list);
	}
	tab[h] = NULL;
	close(fd);
	return (check_tetrimino(tab, (w | (c << 24)) , list, name));
}

save_t	*get_tetrimino(int *len)
{
	save_t *list = NULL;
	save_t *tmp1 = NULL;
	DIR *fd = opendir("tetriminos");
	struct dirent *dir = NULL;

	if (!fd)
		return (NULL);
	dir = readdir(fd);
	while (dir) {
		tmp1 = next_tetrimino(my_strcat("tetriminos/", dir->d_name)
		, list, dir->d_name);
		if (tmp1 != list)
			list = tmp1;
		else if (dir->d_name[0] != '.')
			list = add_error(dir->d_name, list);
		get_next_line(-1);
		dir = readdir(fd);
	}
	closedir(fd);
	for (save_t *tmp = list; tmp; tmp = tmp->next, *len += 1);
	return (list);
}
