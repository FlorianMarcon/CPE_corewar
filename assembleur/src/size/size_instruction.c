/*
** EPITECH PROJECT, 2017
** size_instruction
** File description:
** size_instruction
*/

#include "header_asm.h"
#include "my.h"
int	size_function(char *str);
int	size_argument(char *str);

int	size_instruction(char **tab)
{
	int count = 0;

	count += size_function(tab[0]);
	count += size_argument(tab[1]);
	return (count);
}
