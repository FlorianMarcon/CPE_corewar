/*
** EPITECH PROJECT, 2017
** and_instruction
** File description:
** and_instruction
*/

#include "header_corewar.h"

void	and_instruction_indexe(champion_t *ch, int *arr, int *dec)
{
	int val;

	if (dec[0] == T_REG)
		arr[0] = ch->r[arr[0] - 1];
	if (dec[1] == T_REG)
		arr[1] = ch->r[arr[1] - 1];
	val = arr[0] & arr[1];
	ch->r[arr[2] - 1] = val;
	if (val == 0)
		ch->carry = true;
	else
		ch->carry = false;
}
int	and_instruction(corewar_t *core, champion_t *ch)
{
	int *dec = decoding_byte(core->memory[(ch->pc + 1) % MEM_SIZE]);
	int arr[3];
	int var = 2;

	if (dec[2] != T_REG) {
		ch->pc++;
		return (1);
	}
	for (int i = 0; i != 3; i++) {
		arr[i] = load_value_by_type(core, dec[i], (ch->pc + var)
								% MEM_SIZE);
		if (dec[i] == T_REG)
			var++;
		else if (dec[i] == T_IND)
				var += 2;
		else
			var += 4;
	}
	and_instruction_indexe(ch, arr, dec);
	ch->pc = (ch->pc + var) % MEM_SIZE;
	return (0);
}
