/*
** EPITECH PROJECT, 2017
** create_corewar
** File description:
** create_corewar
*/

#include "header_corewar.h"
#include "op.h"

int	create_corewar(corewar_t *core, char **cmd)
{
	set_virgil_corewar(core);
	cmd = set_dump(core, cmd);
	core->champion = create_list_champion(cmd);
	core->nb_champion = len_list(core->champion);
	core->cycle = 0;
	if (core->nb_champion < 2)
		return (1);
	set_memory(core);
	return (0);
}
