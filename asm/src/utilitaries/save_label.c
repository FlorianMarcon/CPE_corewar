/*
** EPITECH PROJECT, 2017
** save_label
** File description:
** save_label
*/

#include <stdlib.h>
#include "my.h"
#include "header_asm.h"
char	*my_strndup(char *str, int n);

int	save_label(analyse_file_t *an, char *label)
{
	label_t *lab = malloc(sizeof(*lab));

	if (lab == NULL)
		return (0);
	lab->name = my_strndup(label, my_strlen(label) - 1);
	lab->position = an->count;
	if (an->label == NULL) {
		if ((an->label = malloc(sizeof(linked_list_t))) == NULL) {
			free(lab);
			return (0);
		}
		an->label->next = NULL;
		an->label->data = lab;
	} else {
		create_node(an->label, lab);
	}
	return (1);
}
