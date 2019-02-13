/*
** EPITECH PROJECT, 2017
** get_opcode_byte
** File description:
** get_opcode_byte
*/

#include "header_corewar.h"

int	get_opcode_byte(champion_t *ch, corewar_t *core)
{
	short i = 0;
	int pc = ch->pc % MEM_SIZE;

	while (op_tab[i].code != 0) {
		if (core->memory[pc] == op_tab[i].code)
			return (op_tab[i].code);
		i++;
	}
	return (0);
}
