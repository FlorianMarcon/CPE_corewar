/*
** EPITECH PROJECT, 2017
** write_function
** File description:
** write_function
*/

#include <unistd.h>
#include "header_asm.h"

int	write_function(fd_t *fd, char *func, int count)
{
	char c = search_function(func);

	(void)count;
	if (write(fd->new, &c, 1) == -1)
		return (1);
	return (0);
}
