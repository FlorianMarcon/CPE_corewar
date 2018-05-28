/*
** EPITECH PROJECT, 2017
** zjmp_instruction
** File description:
** zjmp_instruction
*/

#include "header_corewar.h"

int	zjmp_instruction(corewar_t *core, champion_t *ch)
{
	short nb = load_short_variable(core, ch->pc + 1);

	if (ch->carry == false)
		ch->pc += 1;
	else
		ch->pc = (ch->pc + nb) % core->size_memory;
	return (0);
}
