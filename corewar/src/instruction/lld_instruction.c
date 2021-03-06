/*
** EPITECH PROJECT, 2017
** lld_instruction
** File description:
** lld_instruction
*/

#include "header_corewar.h"

void	lld_instruction_load_value(corewar_t *core, champion_t *ch, int *dec)
{
	int decal = 2;

	if (dec[0] == T_DIR) {
		dec[0] = load_integer_variable(core, ch->pc + decal);
		dec[0] = load_integer_variable(core, ch->pc + dec[0]);
		decal += 4;
	} else {
		dec[0] = load_short_variable(core, ch->pc + decal);
		decal += 2;
	}
	dec[1] = core->memory[ch->pc++];
	if (dec[1] <= 0 || dec[1] > REG_NUMBER)
		dec[1] = 5;
}
int	lld_instruction(corewar_t *core, champion_t *ch)
{
	int *dec = decoding_byte(core->memory[(ch->pc + 1)
						% core->size_memory]);

	if (dec[1] != T_REG || (dec[0] != T_IND && dec[0] != T_IND)) {
		ch->pc++;
		return (1);
	}
	lld_instruction_load_value(core, ch, dec);
	ch->r[dec[1] - 1] = dec[0];
	if (dec[0] == 0)
		ch->carry = true;
	else
		ch->carry = false;
	return (0);
}
