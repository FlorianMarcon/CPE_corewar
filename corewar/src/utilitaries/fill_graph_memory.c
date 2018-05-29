/*
** EPITECH PROJECT, 2017
** fill_graph_memory
** File description:
** fill_graph_memory
*/

void	fill_graph_memory(corewar_t *core, champion_t *ch, int start, int nb)
{
	for (unsigned int i = 0; i != nb; i++) {
		core->memory[(start + i) % MEM_SIZE] = ch->number;
	}
}
