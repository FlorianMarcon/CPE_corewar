/*
** EPITECH PROJECT, 2017
** choice_command
** File description:
** choice_command
*/

#include <unistd.h>
#include <stdlib.h>
#include "header_asm.h"
#include "op.h"
#include "my.h"

int	choice_command(fd_t *fd, char *cmp)
{
	int i = 0;
	char c = 0;

	while (op_tab[i].code != 0) {
		if (my_strcmp(cmp, op_tab[i].mnemonique) == 0) {
			c = op_tab[i].code;
		}
		i++;
	}
	if (c == 0 || write(fd->fd_new, &c, 1) == -1)
		return (-1);
	return (1);
}
