/*
** EPITECH PROJECT, 2017
** label_is_present_in_file
** File description:
** label_is_present_in_file
*/

#include <stdlib.h>
#include "header_asm.h"
#include "my.h"
#include "op.h"

int	analyse_label_instruction(char *argument, linked_list_t *l)
{
	char **arg = parsing_str(argument, SEPARATOR_CHAR);
	int var;

	if (arg == NULL)
		return (0);
	for (unsigned int i = len_tab(arg); i--;) {
		var = which_variable(arg[i]);
		if (var == T_DIR && label_is_present_in_file(arg[i], l) == 0) {
			free(arg);
			return (0);
		}
	}
	free(arg);
	return (1);
}
int	label_is_present_in_file(char *label, linked_list_t *l)
{
	label_t *node = NULL;

	if (label == NULL || l == NULL)
		return (0);
	if (label[1] != ':')
		return (1);
	while (l != NULL) {
		node = (label_t *)l->data;
		if (node == NULL)
			return (0);
		else if (my_strcmp(node->name, &label[2]) == 0)
			return (1);
		else
			l = l->next;
	}
	return (0);
}
