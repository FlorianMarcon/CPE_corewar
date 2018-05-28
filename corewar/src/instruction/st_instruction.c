/*
** EPITECH PROJECT, 2017
** st_instruction
** File description:
** st_instruction
*/

#include "header_corewar.h"

void	st_instruction_load_value(int *dec, corewar_t *core, champion_t *ch)
{
	dec[0] = core->memory[(ch->pc + 2) % MEM_SIZE];
	if (dec[0] <= 0 || dec[0] > REG_NUMBER)
		dec[0] = 5;
	dec[0] = ch->r[dec[0] - 1];
	if (dec[1] == T_REG) {
		dec[1] = core->memory[(ch->pc + 3) % MEM_SIZE];
		if (dec[1] <= 0 || dec[1] > REG_NUMBER)
			dec[1] = 5;
		ch->r[dec[1] - 1] = dec[0];
		ch->pc = (ch->pc + 4) % core->size_memory;
	} else if (dec[1] == T_IND) {
		dec[1] = load_short_variable(core, ch->pc + 3);
		write_integer(core, (ch->pc + dec[1]) % IDX_MOD, dec[0]);
		ch->pc = (ch->pc + 5) % MEM_SIZE;
	}
}
int	st_instruction(corewar_t *core, champion_t *ch)
{
	int *dec = decoding_byte(core->memory[ch->pc + 1]);

	if (dec[0] != T_REG || (dec[1] == T_DIR)) {
		ch->pc++;
		return (1);
	}
	st_instruction_load_value(dec, core, ch);
	return (0);
}
