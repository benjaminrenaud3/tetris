/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** clock
*/

#include "my.h"
#include "printf.h"

int	my_clock(double wait)
{
	static double past = 0.;
	double now = (double)clock() / (double)CLOCKS_PER_SEC;

	if (now - past >= wait) {
		past = now;
		return (1);
	}
	return (0);
}
