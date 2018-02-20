/*
** EPITECH PROJECT, 2017
** assembleur
** File description:
** assembleur
*/

#include <unistd.h>
#include <stdlib.h>
#include "header_asm.h"
int	first_part(char *path);
fd_t	*open_create_file(char *path);

int	assembleur(char *path)
{
	fd_t *fd = open_create_file(path);

	if (fd == NULL)
		return (84);
	close(fd->fd_new);
	close(fd->fd_old);
	free(fd);
	return (0);
}
