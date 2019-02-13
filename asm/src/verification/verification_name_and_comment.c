/*
** EPITECH PROJECT, 2017
** verification_name_and_comment
** File description:
** verification_name_and_comment
*/

#include <stdlib.h>
#include "header_asm.h"
#include "my.h"
#include "op.h"

int	verification_name(int fd)
{
	char *str = NULL;
	char **tab = NULL;
	int res;
	if ((str = get_next_instruction(fd)) == NULL) {
		return (0);
	}
	if ((tab = parsing_str(str, ' ' | '\t')) == NULL) {
		return (0);
	} else {
		if (len_tab(tab) != 2 || my_strcmp(NAME_CMD_STRING, tab[0])
									!= 0) {
			res = 0;
		} else if (recuperate_string(tab[1]) == NULL){
			res = 0;
		} else {
			res = 1;
		}
		free(tab);
		return (res);
	}
}
int	verification_comment(int fd)
{
	char *str = NULL;
	char **tab = NULL;

	if ((str = get_next_instruction(fd)) == NULL)
		return (0);
	else if ((tab = parsing_str(str, ' ' | '\t')) == NULL)
		return (0);
	else {
		if (len_tab(tab) != 2 || my_strcmp(COMMENT_CMD_STRING, tab[0])
									!= 0) {
			free(tab);
			return (0);
		} else if (recuperate_string(tab[1]) == NULL){
			free(tab);
			return (0);
		} else {
			free(tab);
			return (1);
		}
	}
}

int	verification_name_and_comment(int fd)
{
	if (verification_name(fd) == 0 || verification_comment(fd) == 0)
		return (0);
	else
		return (1);
}
