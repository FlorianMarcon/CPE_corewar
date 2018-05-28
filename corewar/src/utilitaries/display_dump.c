/*
** EPITECH PROJECT, 2017
** display_dump
** File description:
** display_dump
*/

#include "header_corewar.h"

void	display_dump_line(int nb)
{
	char *str;

	if (nb != 0 && ((nb) % 32) == 0 && (str = convert_deci_to_hexa(nb)) != NULL) {
		my_printf("\n%s", str);
		for (unsigned int i = my_strlen(str); i != 5; i++)
			my_printf(" ");
		my_printf(": ");
		free(str);
		str = NULL;
	}

}
void	display_dump(corewar_t *core)
{
	char *str = NULL;
	char *tmp;

	my_printf("0    : ");
	for (unsigned int i = 0; i != MEM_SIZE; i++) {
		display_dump_line(i);
		str = convert_deci_to_hexa(core->memory[i]);
		if (str != NULL && my_strlen(str) == 1) {
			tmp = str;
			str = my_strcat("0", str);
			free(tmp);
		}
		if (str != NULL) {
			my_printf("%s ", str);
			free(str);
			str = NULL;
		}
	}
	my_printf("\n");
}
