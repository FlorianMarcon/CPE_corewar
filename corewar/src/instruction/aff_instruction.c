/*
** EPITECH PROJECT, 2017
** aff_instruction
** File description:
** aff_instruction
*/

#include "header_corewar.h"

int	aff_instruction(corewar_t *core, champion_t *ch)
{
	int *dec = decoding_byte(core->memory[(ch->pc + 1) % MEM_SIZE]);
	int val = 5;

	if (dec[0] != T_REG) {
		ch->pc++;
		return (1);
	}
	val = core->memory[(ch->pc + 2) % MEM_SIZE];
	if (val <= 0 || val > REG_NUMBER)
		val = 5;
	my_printf("%c", ch->r[val - 1]);
	ch->pc = (ch->pc + 3) % MEM_SIZE;
	return (0);
}
