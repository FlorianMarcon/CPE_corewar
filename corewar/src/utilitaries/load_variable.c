/*
** EPITECH PROJECT, 2017
** load_integer_variable
** File description:
** load_integer_variable
*/

#include "header_corewar.h"
#include "my.h"

int	load_integer_variable(corewar_t *core, int pc)
{
	int a = core->memory[pc % core->size_memory];

	a = a << 8;
	a += core->memory[(pc + 1) % core->size_memory];
	a = a << 8;
	a += core->memory[(pc + 2) % core->size_memory];
	a = a << 8;
	a += core->memory[(pc + 3) % core->size_memory];
	return (a);
}

short	load_short_variable(corewar_t *core, int pc)
{
	short a = 0;
	char *var = (char *)(&a);

	var[1] = core->memory[pc % core->size_memory];
	var[0] = core->memory[(pc + 1) % core->size_memory];
	return (a);
}
