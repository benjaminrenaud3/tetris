/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** get control
*/

#include "my.h"
#include "printf.h"

void print_help(char *name)
{
	my_printf("Usage: %s [options]\n", name);
	my_putstr("Options:\n");
	my_putstr("--help\t\tDisplay this help\n");
	my_putstr("-L --level={num}\tStart Tetris at level num (def: 1)\n");
	my_putstr("-l --key-left={K}\tMove the tetrimino LEFT using the K key");
	my_putstr(" (def: left arrow)\n");
	my_putstr("-r --key-right={K}\tMove the tetrimino RIGHT using");
	my_putstr(" the K key (def: right arrow)\n");
	my_putstr("-t --key-turn={K}\tTURN the tetrimino clockwise 90d");
	my_putstr(" using the K key (def: toparrow)\n");
	my_putstr("-d --key-drop={K}\tDROP the tetrimino using the K key");
	my_putstr(" (def: down arrow)\n");
	my_putstr("-q --key-quit={K}\tQUIT the game using the K key");
	my_putstr(" (def: 'q' key)\n");
	my_putstr("-p --key-pause={K}\tPAUSE/RESTART the game using the K key");
	my_putstr(" (def: space bar)\n");
	my_putstr("--map-size={row,col}\tSet the numbers of rows and columns");
	my_putstr(" of the map (def: 20,10)\n");
	my_putstr("-w --without-next\tHide next tetrimino (def: false)\n");
	my_putstr("-D --debug\t\tDebug mode (def: false)\n");
}

char	**get_control(int argc, char **argv, save_t *list, char **env)
{
	char **tab_control;

	if (cmp("--help", argv[1]) == 0) {
		print_help(argv[0]);
		return (0);
	}
	else
		tab_control = verif_option(argc, argv, list, env);
	return (tab_control);
}
