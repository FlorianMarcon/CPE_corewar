/*
** EPITECH PROJECT, 2017
** lfork_instruction
** File description:
** lfork_instruction
*/

#include "header_corewar.h"

int	lfork_instruction(corewar_t *core, champion_t *ch)
{
	champion_t *new = copy_champion(ch);
	int val = load_short_variable(core, ch->pc + 1);

	if (new == NULL) {
		ch->pc++;
		return (1);
	}
	create_node(core->champion, new);
	new->pc = (ch->pc + val % IDX_MOD) % MEM_SIZE;
	core->nb_champion++;
	return (0);
}
