/*
** EPITECH PROJECT, 2017
** write_string
** File description:
** write_string
*/

#include "header_asm.h"
#include <unistd.h>

int	write_string(int fd, char *str)
{
	int res = write(fd, str, sizeof(str));

	return (res);
}
