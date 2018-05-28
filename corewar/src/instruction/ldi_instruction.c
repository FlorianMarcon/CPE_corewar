/*
** EPITECH PROJECT, 2017
** ldi_instruction
** File description:
** ldi_instruction
*/

#include "header_corewar.h"

void	ldi_instruction_load_value(int *dec, corewar_t *core, champion_t *ch)
{
	int i = 0;
	int decal = 2;

	for (; i != 3; i++) {
		if (dec[i] == T_REG) {
			dec[i] = core->memory[(ch->pc + decal) % MEM_SIZE];
			if (dec[i] <= 0 || dec[i] > REG_NUMBER)
				dec[i] = 5;
			if (i != 2)
				dec[i] = ch->r[dec[i] - 1];
			decal++;
		} else if (dec[i] == T_DIR) {
			dec[i] = load_short_variable(core, ch->pc + decal);
			dec[i] = load_integer_variable(core, ch->pc + dec[i]);
			decal += 2;
		} else {
			dec[i] = load_short_variable(core, ch->pc + decal);
			decal += 2;
		}
	}
}
int	ldi_instruction(corewar_t *core, champion_t *ch)
{
	int *dec = decoding_byte(core->memory[(ch->pc + 1) % MEM_SIZE]);
	int sum = 0;

	if (dec == NULL || dec[2] != T_REG || dec[1] == T_IND) {
		ch->pc++;
		return (1);
	}
	ldi_instruction_load_value(dec, core, ch);
	ch->pc = (ch->pc + 7) % MEM_SIZE;
	sum = dec[0] + dec[1];
	ch->r[dec[2] - 1] = load_integer_variable(core, ch->pc + sum % IDX_MOD);
	if (sum == 0)
		ch->carry = true;
	else
		ch->carry = false;
	return (0);
}
