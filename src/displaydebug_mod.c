/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** get_control
*/

#include "my.h"
#include "printf.h"

void print_c_per_c(char *str)
{
	int cpt = 0;

	for (; str[cpt] != '\0'; cpt += 1) {
		if (str[cpt] == ' ')
			my_printf("(space)");
		else
			my_printf("%c", str[cpt]);
	}
	my_printf("\n");
}

void display_key(char **control)
{
	my_printf("*** DEBUG MODE ***\n");
	my_printf("Key Left : ");
	print_c_per_c(control[1]);
	my_printf("Key Right : ");
	print_c_per_c(control[2]);
	my_printf("Key Turn : ");
	print_c_per_c(control[3]);
	my_printf("Key Drop : ");
	print_c_per_c(control[4]);
	my_printf("Key Quit : ");
	print_c_per_c(control[5]);
	my_printf("Key Pause : ");
	print_c_per_c(control[6]);
	my_printf("Next : ");
	if (cmp("False", control[7]) == 0)
		my_printf("Yes\n");
	else
		my_printf("No\n");
	my_printf("Level : %s\n", control[0]);
	my_printf("Size : %s\n", control[8]);
}

int nbr_maker(char *str, int i)
{
	int nb = 0;

	for (; str[i] >= '0' && str[i] <= '9'; i++)
		nb = nb * 10 + str[i] - '0';
	return (nb);
}

void display_control(char **control)
{
	for (int cpt = 0; cpt != 9; cpt++) {
		if (verif_double(control, control[cpt]) == 1)
			exit(84);
	}
	verify_and_change_size(control[8]);
	verify_level(control[0]);
	display_key(control);
}

int display_debugmod(char **control, save_t *list, char **env)
{
	display_control(control);
	nbr_tetrimino(list);
	print_list(list);
	my_printf("Press any key to start Tetris\n");
	waiting_keys(env);
	return (0);
}
