/*
** EPITECH PROJECT, 2017
** create_list_champion
** File description:
** create_list_champion
*/

#include "header_corewar.h"
#include "my.h"

linked_list_t	*add_in_list_champion(linked_list_t *list, char *path,
						int load_address, int *nb)
{
	int number = *nb;
	champion_t *champ;

	champ = create_champion(number++, load_address, path);
	if (champ != NULL && list == NULL)
		list = create_list(champ);
	else if (champ != NULL)
		create_node(list, champ);
	else
		number--;
	*nb = number;
	return (list);
}
linked_list_t	*create_list_champion(char **path)
{
	linked_list_t *list = NULL;
	int nb = 1;
	int load_address = -1;

	if (path == NULL)
		return (NULL);
	for (unsigned int i = 0; path[i] != NULL; i++) {
		if (my_strcmp("-n", path[i]) == 0 && my_str_isnum(path[++i]))
			nb = my_getnbr(path[i]);
		else if (my_strcmp("-a", path[i]) == 0 &&
							my_str_isnum(path[++i]))
			load_address = my_getnbr(path[i]);
		else {
			list = add_in_list_champion(list, path[i],
							load_address, &nb);
			load_address = -1;
		}
	}
	return (list);
}
