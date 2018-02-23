/*
** EPITECH PROJECT, 2017
** verification_file
** File description:
** verification_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "header_asm.h"
#include "op.h"
int	verification_name_and_comment(int fd);
int	verification_instruction(char **tab);

/*
analyse_file_t	*save_label_and_count_size(char *path)
{
	int fd = open(path, O_RDONLY);
	analyse_file_t *an = NULL;
	char *str = NULL;
	char *tab = NULL;

	if (fd == -1 || verification_name_and_comment(fd) == 0)
		return (NULL);
	if ((an = malloc(sizeof(*an))) == NULL)
		return (NULL);
	while ((str = get_next_instruction(fd)) != NULL) {
		tab = parsing_str(str, ' ' | '\t');
		if (is_label(tab[0]) {
			save_label(an, tab[0]);
			tab = &tab[1];
		}
		if (tab[0] != NULL) {
			if (verification_instruction(tab)) {
				an->count += size_instruction(tab);
			} else {
				free(str);
				free(tab);
				return (NULL);
			}
		}
		free(str);
		free(tab);
	}
	return (an);
}
analyse_file_t	*verification_file(char *path)
{
	analyse_file_t *fl = save_label_and_count_size(path);

	if (fl == NULL)
		return (NULL);
	return (fl)
}*/
