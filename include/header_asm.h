/*
** EPITECH PROJECT, 2017
** header_asm
** File description:
** header_asm
*/

#include "my.h"

#ifndef ASM_
#define ASM_

typedef struct label {
	char *name;
	int position;
}label_t;

typedef struct analyse_file {
	linked_list_t *label;
	int count;
}analyse_file_t;

typedef struct fd {
	int fd_old;
	int fd_new;

	int write_byte;
}fd_t;

#endif
