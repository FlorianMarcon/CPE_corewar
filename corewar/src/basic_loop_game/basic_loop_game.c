/*
** EPITECH PROJECT, 2017
** basic_loop_game
** File description:
** basic_loop_game
*/

#include "header_corewar.h"

int	basic_loop_game(corewar_t *core)
{
	core->last_alive = core->champion->data;
	while (is_end(core->champion) == 0) {
		if (core->cycle == core->dump)
			display_dump(core);
		evolve_game(core);
		destroy_dead_champion(core);
	}
	if (core->dump == -1)
		my_printf("The player %i (%s) has won.\n", core->last_alive->number, core->last_alive->name);
	return (0);
}
