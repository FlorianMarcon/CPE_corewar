/*
** EPITECH PROJECT, 2017
** sti_instruction
** File description:
** sti_instruction
*/

#include "header_corewar.h"

int	*sti_instruction_index(corewar_t *core, champion_t *ch)
{
	int *dec = decoding_byte(core->memory[(ch->pc + 1) %
							core->size_memory]);
	int decalage = 3;

	if (dec[0] != T_REG)
		return (NULL);
	dec[0] = 0;
	for (unsigned int i = 1; i != 3; i++) {
		if (dec[i] == T_DIR) {
			dec[0] += load_short_variable(core, ch->pc + decalage);
			decalage += 2;
		} else if (dec[i] == T_REG) {
			dec[0] += core->memory[(ch->pc + decalage) % MEM_SIZE];
			decalage++;
		} else {
			return (NULL);
		}
	}
	dec[1] = core->memory[(ch->pc + 2) % MEM_SIZE];
	dec[2] = decalage;
	return (dec);
}
int	sti_instruction(corewar_t *core, champion_t *ch)
{
	int *dist = sti_instruction_index(core, ch);
	int reg = 0;

	if (dist == NULL || dist[1] - 1 < 0 || dist[1] - 1 > REG_SIZE) {
		ch->pc++;
		return (1);
	}
	reg = ch->r[dist[1] - 1];
	write_integer(core, ch->pc + dist[0], reg);
	fill_graph_memory(core, ch, ch->pc + dist[0], 4);
	ch->pc = (ch->pc + dist[2]) % core->size_memory;
	return (0);
}
