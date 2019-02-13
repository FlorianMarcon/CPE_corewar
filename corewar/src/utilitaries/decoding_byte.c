/*
** EPITECH PROJECT, 2017
** decoding_byte
** File description:
** decoding_byte
*/

#include <stdlib.h>
#include "my.h"
#include "header_corewar.h"
#include "op.h"

int	bite_correspondance(char var)
{
	switch (var) {
		case 1: var = T_REG;
		break;
		case 2: var = T_DIR;
		break;
		case 3: var = T_IND;
		break;
		default: var = 0;
	}
	return (var);
}
int	*decoding_byte(char encode)
{
	char mask = 3;
	int *tab = malloc(sizeof(*tab) * 5);
	char var;

	if (tab == NULL)
		return (NULL);
	for (short i = 3; i >= 0; i--) {
		var = encode;
		var = var & mask;
		encode = encode >> 2;
		tab[i] = bite_correspondance(var);
	}
	tab[4] = 0;
	return (tab);
}
