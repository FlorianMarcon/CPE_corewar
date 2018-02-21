/*
** EPITECH PROJECT, 2017
** second_part
** File description:
** second_part
*/

#include <unistd.h>
#include <stdlib.h>
#include "header_asm.h"
#include "op.h"
#include "my.h"
int	choice_command(fd_t *fd, char *cmp);
char	*get_next_instruction(int fd);
char	**my_str_to_word_array(const char *str);

int	second_part(fd_t *fd)
{
	char *str = NULL;
	char **tab = NULL;
	int res = 0;

	while ((str = get_next_instruction(fd->fd_old)) != NULL) {
		tab = my_str_to_word_array(str);
		if (choice_command(fd, tab[0]) == -1) {
			res = -1;
			break;
		}
	}
	return (res);
}
