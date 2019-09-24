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
	int x;
	int y;
	char *name;
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
} stat_t;

typedef struct game_s {
	save_t *list;
	int len;
	char **control;
	char **map;
	int x;
	int y;
	double wait;
	int next;
	int pause;
	int quit;
	stat_t stat;
} game_t;

struct simple_key{
	char key;
	void (*simple_fill)(char **control, int tabcase, char **argv, int *ind);
};

struct double_key{
	char *strkey;
	void (*double_fill)(char **control, int tabcase, char **argv, int *ind);
};

extern struct simple_key sfunc[];
extern struct double_key dfunc[];

int     init_game(save_t *list, int len, char **control);
void    draw_edge(int x, int y, int size_x, int size_y);
int	cmp_begin(char *str, char *str2);
int     check_rotation(tetris_t *tet, game_t *game, int turn);
void    get_event(tetris_t *tet, game_t *game);
void	verify_level(char *str);
void	verify_and_change_size(char *str);
int	verif_nbr(char *str);
int	verif_double(char **control, char *str);
void	nbr_tetrimino(save_t *list);
int	nbr_maker(char *str, int i);
void    print_list(save_t *list);
void	show_next(char **control, int tabcase, char **argv, int *ind);
void	double_fill_tab(char **control, int tabcase, char **argv, int *ind);
void	simple_fill_tab(char **control, int tabcase, char **argv, int *ind);
char	**get_control(int ac, char **av, save_t *list, char **env);
int	my_strcmp(char *s1, char *s2);
int 	my_cmp(char *str, char *str2);
save_t  *sort_list(save_t *list);
int	my_tab_len(char **tab);
char	*my_strdup(char *str);
void    draw(point_t *list, game_t *game, point_t *next);
stat_t  init_stat(int level);
int	check_loose(game_t *game);
void    add_piece_to_map(point_t *list, char **map);
void    disp_stat(stat_t stat);
void	check_line_tet(game_t *game);
void    clear_old_piece(tetris_t *tet);
int     move_side(tetris_t *tet, game_t *game, int dir);
int     start_game(game_t *game);
tetris_t 	*create_new_piece(game_t *game);
int	move_down(tetris_t *tet, game_t *game);
int	my_getnbr(char *str);
int     my_strlen(char *str);
int     my_strtol(char **str);
int	my_clock(double wait);
char	*my_strcat(char *s1, char *s2);
char	*get_next_line(int fd);
char    **my_str_to_word_array(char *str, char c, int opt);
save_t  *get_tetrimino(int *len);
char    *change_line(char *old, int w, int min);
save_t  *add_tetrimino(char **tab, save_t *list, int c, char *name);
save_t  *add_error(char *name, save_t *list);
int	cmp(char *str, char *str2);
int	cmp_c (char key, char c);
void	fill_case(char *str, char *src);
int	waiting_keys(char **env);
char	**verif_option(int argc, char **argv, save_t *list, char **env);
int	display_debugmod(char **control, save_t *list, char **env);
void fill_tab_start(char **tab);
char *take_key(char *src);
void show_next(char **control, int tabcase, char **argv, int *ind);
char *recup_av_double_dash(char *src);
void simple_fill_tab(char **control, int tabcase, char **argv, int *ind);
void double_fill_tab(char **control, int tabcase, char **argv, int *ind);
int simple_dash(char **argv, char **control, int *ind, int disp);
int double_dash(char **argv, char **control, int *ind, int disp);
char **verif_option(int argc, char **argv, save_t *list, char **env);

#endif /* MY_H_ */
