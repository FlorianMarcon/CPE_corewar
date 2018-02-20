/*
** EPITECH PROJECT, 2017
** open_create_file
** File description:
** open_create_file
*/

#include <stdlib.h>
#include <unistd.h>
#include "header_asm.h"
int	create_new_file(char *path_old);
int	verify_file_name(char *path);

fd_t	*open_create_file(char *path)
{
	fd_t *fd = malloc(sizeof(*fd));

	if (fd == NULL)
		return (0);
	fd->fd_old = verify_file_name(path);
	if (fd->fd_old == -1)
		return (NULL);
	fd->fd_new = create_new_file(path);
	if (fd->fd_new == -1) {
		close(fd->fd_old);
		free(fd);
		return (NULL);
	}
	return (fd);
}
