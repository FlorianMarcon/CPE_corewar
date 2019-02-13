/*
** EPITECH PROJECT, 2017
** create_corewar
** File description:
** create_corewar
*/

#include "header_corewar.h"
#include "op.h"

void	set_virgil_corewar(corewar_t *core)
{
	core->champion = NULL;
	core->nb_champion = 0;
	core->cycle_to_die = CYCLE_TO_DIE;
	core->cycle_delta = CYCLE_DELTA;
	core->nbr_max_live = NBR_LIVE;
	core->nbr_live = 0;
	core->nbr_live_total = 0;
	core->size_memory = MEM_SIZE;
	core->dump = -1;
	core->graphical = false;
	core->last_alive = NULL;
	for (unsigned int i = 0; i != MEM_SIZE; i++) {
		core->memory[i] = 0;
		core->graph_memory[i] = 0;
	}
}
