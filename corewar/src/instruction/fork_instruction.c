/*
** EPITECH PROJECT, 2017
** fork_instruction
** File description:
** fork_instruction
*/

#include "header_corewar.h"

champion_t	*copy_champion(champion_t *ch)
{
	champion_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->pc = ch->pc;
	new->carry = ch->carry;
	new->alive = ch->alive;
	new->action_cycle = ch->action_cycle;
	new->life_cycle = ch->life_cycle;
	new->number = ch->number;
	new->prog_size = ch->prog_size;
	new->load_address = ch->load_address;
	for (unsigned int i = 0; i != REG_NUMBER; i++)
		new->r[i] = ch->r[i];
	my_strncpy(new->name, ch->name, PROG_NAME_LENGTH);
	my_strncpy(new->programme, ch->programme, MEM_SIZE / 6);
	my_strncpy(new->comment, ch->comment, COMMENT_LENGTH);
	return (new);
}
int	fork_instruction(corewar_t *core, champion_t *ch)
{
	champion_t *new = copy_champion(ch);
	int val = load_short_variable(core, ch->pc + 1);


	if (new == NULL) {
		ch->pc++;
		return (1);
	}
	create_node(core->champion, new);
	new->pc = (ch->pc + val % IDX_MOD) % MEM_SIZE;
	ch->pc = (ch->pc + 3) % MEM_SIZE;
	return (0);
}
