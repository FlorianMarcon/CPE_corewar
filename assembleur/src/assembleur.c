/*
** EPITECH PROJECT, 2017
** assembleur
** File description:
** assembleur
*/

#include <unistd.h>
#include <stdlib.h>
#include "header_asm.h"
fd_t	*open_create_file(char *path);
int	first_part(fd_t *fd);
int	second_part(fd_t *fd);

int	assembleur(char *path)
{
	fd_t *fd = open_create_file(path);
	int res;

	if (fd == NULL)
		return (84);
	res = first_part(fd);
	if (res != 84)
		res = second_part(fd);
	close(fd->fd_new);
	close(fd->fd_old);
	free(fd);
	return (res);
}
