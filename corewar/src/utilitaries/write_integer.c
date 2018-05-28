/*
** EPITECH PROJECT, 2017
** write_integer
** File description:
** write_integer
*/

#include "header_corewar.h"

void	write_integer(corewar_t *core, int pc, int nb)
{
	char *var = (char *)(&nb);

	core->memory[pc % MEM_SIZE] = var[3];
	core->memory[(pc + 1) % MEM_SIZE] = var[2];
	core->memory[(pc + 2) % MEM_SIZE] = var[1];
	core->memory[(pc + 3) % MEM_SIZE] = var[0];
}
