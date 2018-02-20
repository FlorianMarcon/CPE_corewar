/*
** EPITECH PROJECT, 2017
** first_part
** File description:
** first_part
*/

#include <stdlib.h>
#include <unistd.h>
#include "header_asm.h"
#include "op.h"
#include "my.h"
#include "my_printf.h"

char	*get_next_instruction(int fd);
char	*recuperate_string(char *str);
int	verify_file_name(char *path);
int	create_new_file(char *path_old);
int	field_header(header_t *h, fd_t *fd);

int	write_inutile_byte(int fd, int nb)
{
	int i = 0;

	while (i != nb) {
		if (write(fd, "\0", 1) == -1)
			return (0);
		i++;
	}
	return (1);
}

int	first_part(fd_t *fd)
{
	header_t *header = malloc(sizeof(*header));

	if (header == NULL)
		return (0);
	field_header(header, fd);
	write(fd->fd_new, header, sizeof(*header));
	free(header);
	return (1);
}
