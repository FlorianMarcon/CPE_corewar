/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "header_corewar.h"
#include "bonus.h"

int	main(int ac, char **av)
{
	(void)ac;
	corewar_t core;

	if (create_corewar(&core, &av[1]))
		return (84);
	loop_game_graphique(&core);
	return (0);
}
