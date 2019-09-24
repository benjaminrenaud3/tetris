/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>

typedef struct save_s {
	char **tab1;
	char **tab2;
	char **tab3;
	char **tab4;
	int color;
	struct save_s *next;
} save_t;

typedef struct point_s {
	int x;
	int y;
	int color;
	struct point_s *next;
} point_t;

typedef struct tetris_s {
	point_t *list[4];
	int state;
}tetris_t;

typedef struct stat_s {
	int time_start;
	int level;
	int line;
	int score;
	int highscore;
} stat_t;

typedef struct move_s {
	int rotate;
	int move;
	double score;
	struct move_s *next;
} move_t;

typedef struct back_s {
	char *line;
	struct back_s *next;
} back_t;

int     move_only_one_side(point_t *list, char **map);
void	make_move(move_t *all, tetris_t *tet, char **map);
int     move_only_one_down(point_t *list, char **map);
double	calc_score(point_t *list, char **map, int pos);
void	reload_list(point_t *tmp, point_t *tmp2);
tetris_t        *make_a_copy(tetris_t *tet);
void    do_the_best_move(tetris_t *tet, tetris_t *next, char **map);
double	get_hole(char **map);
double	get_completed_line(char **map);
double	get_aggregate_height(char **map);
double	get_bumpiness(char **map);
void    draw(point_t *list, char **map, back_t *back, point_t *next);
point_t *add_to_list(int x, int y, int color, point_t *list);
stat_t  init_stat(void);
int	check_loose(char **map);
void    add_piece_to_map(point_t *list, char **map);
void    disp_stat(stat_t stat);
void	check_line_tet(char **map, stat_t *stat);
void    clear_old_piece(tetris_t *tet);
int     move_side(tetris_t *tet, char **map, int dir);
int     start_game(save_t *list, int len, back_t *back);
tetris_t 	*create_new_piece(save_t *list, int len);
int	move_down(tetris_t *tet, char **map);
int	move_only_one_side(point_t *list, char **map);
int	move_only_one_down(point_t *list, char **map);
int	my_getnbr(char *str);
int     my_strlen(char *str);
int     my_strtol(char **str);
int	my_clock(double wait);
char	*my_strcat(char *s1, char *s2);
char	*get_next_line(int fd);
char    **my_str_to_word_array(char *str, char c, int opt);
save_t  *get_tetrimino(int *len);
char    *change_line(char *old, int w, int min);
save_t  *add_tetrimino(char **tab, save_t *list, int c);

#endif /* MY_H_ */
