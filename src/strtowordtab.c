/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** strtowordtab
*/

#include "my_ftp.h"

char		**parse_command(char *buf)
{
	char	**tab = malloc(sizeof(char *) * 3);
	size_t	i = 0;

	if (tab == NULL)
		return NULL;
	tab[0] = buf;
	for (i = 0; i < strlen(buf) && buf[i] != ' ' && buf[i] != '\0'
	&& buf[i] != '\n' && buf[i] != '\r'; i++);
	tab[0][i] = '\0';
	if (buf[i + 1]) {
		tab[1] = &buf[i + 1];
		for (i = 0; i < strlen(tab[1]) && tab[1][i] != '\0' &&
		tab[1][i] != '\n' && tab[1][i] != '\r'; i++);
		tab[1][i] = '\0';
	}
	else
		tab[1] = NULL;
	tab[2] = NULL;
	return tab;
}
