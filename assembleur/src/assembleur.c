/*
** EPITECH PROJECT, 2017
** assembleur
** File description:
** assembleur
*/

#include <unistd.h>
#include <stdlib.h>
#include "header_asm.h"

int	assembleur(char *path)
{
	analyse_file_t *f = verification_file(path);

	if (f == NULL)
		return (84);
	return (0);
}
