/*
** EPITECH PROJECT, 2017
** set_dump
** File description:
** set_dump
*/

#include "header_corewar.h"

char	**set_dump(corewar_t *core, char **cmd)
{
	if (core == NULL || cmd == NULL)
		return (NULL);
	for (unsigned int i = 0; cmd[i] != NULL; i++) {
		if (my_strcmp(cmd[i], "-dump") == 0) {
			if (cmd[i + 1] != NULL || my_str_isnum(cmd[i + 1]))
				core->dump = my_getnbr(cmd[i + 1]);
			else
				core->dump = -1;
			cmd[i] = NULL;
			cmd[i + 1] = NULL;
			if (cmd[i + 2] != NULL)
				cmd = my_tabcat(cmd, &cmd[i + 2]);
		} else if (my_strcmp(cmd[i], "-g") == 0) {
			core->graphical = true;
			cmd[i] = NULL;
			if (cmd[i + 1] != NULL)
				cmd = my_tabcat(cmd, &cmd[i + 1]);
		}
	}
	return (cmd);
}
