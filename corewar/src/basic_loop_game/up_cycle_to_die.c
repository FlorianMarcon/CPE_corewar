/*
** EPITECH PROJECT, 2017
** up_cycle_to_die
** File description:
** up_cycle_to_die
*/

#include "header_corewar.h"

void	up_cycle_to_die(corewar_t *core)
{
	if (core->nbr_live > core->nbr_max_live) {
		core->nbr_live = core->nbr_live % core->nbr_max_live;
		core->cycle_to_die -= core->cycle_delta;
	}
	core->cycle++;
}
