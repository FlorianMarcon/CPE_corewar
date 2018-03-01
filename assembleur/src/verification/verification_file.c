/*
** EPITECH PROJECT, 2017
** verification_file
** File description:
** verification_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "header_asm.h"
#include "op.h"
int	verification_name_and_comment(int fd);
int	verification_instruction(char **tab);

analyse_file_t	*verification_file(char *path)
{
	analyse_file_t *fl = count_file_and_save_label(path);
	char *str = NULL;
	char **tab = NULL;
	int fd;

	if (fl == NULL)
		return (NULL);
	if ((fd = open(path, O_RDONLY)) == -1) {
		free(fl);
		return (NULL);
	}
	while ((str = get_next_instruction(fd)) != NULL) {
		tab = parsing_str(str, ' ' | '\t');
		if (is_label(tab[0]) == 0 &&
			label_is_present_in_file(tab[1], fl->label) == 0) {
			free(tab);
			free(fl);
			close(fd);
			return (NULL);
		}
		free(tab);
	}
	close (fd);
	return (fl);
}
