/*
** EPITECH PROJECT, 2017
** load_value_by_type
** File description:
** load_value_by_type
*/

#include "header_corewar.h"
#include "op.h"

int	load_value_by_type(corewar_t *core, int type, int pc)
{
	int value = 0;

	if (core == NULL || (type != T_REG && type != T_DIR && type != T_DIR))
		return (value);
	switch (type) {
		case T_REG: value = core->memory[pc];
				break;
		case T_IND: value = load_short_variable(core, pc);
				break;
		case T_DIR: value = load_integer_variable(core, pc);
				break;
	}
	if (type == T_REG && (value < 1 || value > REG_NUMBER))
		value = 5;
	return (value);
}
