/*
** EPITECH PROJECT, 2017
** first_part
** File description:
** first_part
*/

#include <stdlib.h>
#include <unistd.h>
#include "header_asm.h"
#include "my.h"
#include "my_printf.h"

char	*get_next_instruction(int fd);
char	*recuperate_string(char *str);
int	verify_file_name(char *path);
int	create_new_file(char *path_old);

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
