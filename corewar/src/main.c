/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "header_corewar.h"

int	main(int ac, char **av)
{
	(void)ac;
	corewar_t core;

	if (create_corewar(&core, &av[1]))
		return (84);
	if (core.graphical == true)
		fprintf(stderr, "Graphical Mode\n");
	else
		basic_loop_game(&core);
	return (0);
}
