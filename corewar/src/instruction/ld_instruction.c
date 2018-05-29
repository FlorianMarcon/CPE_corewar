/*
** EPITECH PROJECT, 2017
** ld_instruction
** File description:
** ld_instruction
*/

#include "header_corewar.h"

void	ld_instruction_load_value(corewar_t *core, champion_t *ch, int *dec)
{
	int decal = 2;

	if (dec[0] == T_DIR) {
		dec[0] = load_integer_variable(core, ch->pc + dec[0] % IDX_MOD);
		decal += 4;
	} else {
		dec[0] = load_short_variable(core, ch->pc + decal);
		decal += 2;
	}
	ch->pc = (ch->pc + decal + 1) % MEM_SIZE;
	dec[1] = core->memory[ch->pc];
	if (dec[1] <= 0 || dec[1] > REG_NUMBER)
		dec[1] = 5;
}
int	ld_instruction(corewar_t *core, champion_t *ch)
{
	int *dec = decoding_byte(core->memory[(ch->pc + 1) % core->size_memory]);

	if (dec[1] != T_REG || (dec[0] != T_IND && dec[0] != T_DIR)) {
		ch->pc++;
		return (1);
	}
	ld_instruction_load_value(core, ch, dec);
	ch->r[dec[1] - 1] = dec[0];
 	if (dec[0] == 0)
		ch->carry = true;
	else
		ch->carry = false;
	return (0);
}
