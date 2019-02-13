/*
** EPITECH PROJECT, 2017
** sub_instruction
** File description:
** sub_instruction
*/

#include "header_corewar.h"

void	sub_instruction_indexe(champion_t *ch, int *dec)
{
	int one = dec[0];
	int two = dec[1];
	int three = dec[2];
	int sum = ch->r[one - 1] + ch->r[two - 1];

	ch->r[three - 1] = sum;
	if (sum == 0)
		ch->carry = true;
	else
		ch->carry = false;
	ch->pc = (ch->pc + 5) % MEM_SIZE;
}
void	sub_instruction_load_value(corewar_t *core, champion_t *ch, int *dec)
{
	for (unsigned int i = 0; i != 3; i++) {
		dec[i] = core->memory[(ch->pc + i) % MEM_SIZE];
		if (dec[i] <= 0 || dec[i] > REG_NUMBER)
			dec[i] = 5;
	}
}
int	sub_instruction(corewar_t *core, champion_t *ch)
{
	int *dec = decoding_byte(core->memory[(ch->pc + 1) % MEM_SIZE]);

	if (dec[0] != T_REG || dec[1] != T_REG || dec[2] != T_REG){
		ch->pc++;
		return (1);
	}
	sub_instruction_load_value(core, ch, dec);
	sub_instruction_indexe(ch, dec);
	return (0);
}
