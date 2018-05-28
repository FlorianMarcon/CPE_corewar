/*
** EPITECH PROJECT, 2017
** create_champion
** File description:
** create_champion
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "header_corewar.h"
#include "op.h"
#include "my.h"

int	fill_header(champion_t *champ, int fd)
{
	struct header_s head;

	if (read(fd, &head, sizeof(head)) <= 0)
		return (1);
	integer_little_to_big_endian(&head.magic);
	if (head.magic != COREWAR_EXEC_MAGIC) // a verifier unit test
		return (1);
	my_strcpy(champ->name, head.prog_name);
	my_strcpy(champ->comment, head.comment);
	champ->prog_size = head.prog_size;
	integer_little_to_big_endian(&(champ->prog_size));
	return (0);
}
int	fill_program(champion_t *champ, int fd)
{
	int i = 0;

	while (i != REG_SIZE)
		champ->r[i++] = 0;
	if (read(fd, champ->programme, champ->prog_size) <= 0)
		return (1);
	return (0);
}
champion_t	*create_champion(unsigned int nb, int load_address, char *path)
{
	int fd = open(path, O_RDONLY);

	champion_t *champ;

	if (fd == -1)
		return (NULL);
	else if ((champ = malloc(sizeof(*champ))) == NULL)
		return (NULL);
	if (fill_header(champ, fd) || fill_program(champ, fd)) {
		free(champ);
		return (NULL);
	}
	champ->load_address = load_address;
	champ->number = nb;
	champ->r[0] = champ->number;
	champ->alive = true;
	champ->action_cycle = 0;
	champ->life_cycle = 0;
	return (champ);
}
