/*
** EPITECH PROJECT, 2017
** field_header
** File description:
** field_header
*/

#include <stdlib.h>
#include "op.h"
#include "header_asm.h"
#include "my.h"
char	*get_next_instruction(int fd);
char	*recuperate_string(char *str);

char	*recuperate_for_header(char *argu, fd_t *fd)
{
	char *str = get_next_instruction(fd->fd_old);
	char *var = NULL;

	if (str == NULL || my_strncmp(str, argu, my_strlen(argu)) != 0)
		return (NULL);
	var = recuperate_string(str);
	if (var == NULL)
		return (NULL);
	return (var);
}

int	field_header(header_t *h, fd_t *fd)
{
	char *var = recuperate_for_header(NAME_CMD_STRING, fd);

	if (var == NULL)
		return (84);
	h->magic = COREWAR_EXEC_MAGIC;
	my_strcpy(h->prog_name, var);
	free(var);
	var = recuperate_for_header(COMMENT_CMD_STRING, fd);
	if (var == NULL)
		return (84);
	my_strcpy(h->comment, var);
	return (0);
}
