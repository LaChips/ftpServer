/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** init_function
*/

#include "my_ftp.h"

char	**init_cmd(void)
{
	char	**tab = malloc(sizeof(char *) * 12);

	if (tab == NULL)
		return NULL;
	tab[0] = "USER";
	tab[1] = "PASS";
	tab[2] = "PWD";
	tab[3] = "CDUP";
	tab[4] = "CWD";
	tab[5] = "LIST";
	tab[6] = "QUIT";
	tab[7] = "HELP";
	tab[8] = "DELE";
	tab[9] = "RETR";
	tab[10] = "NOOP";
	tab[11] = NULL;
	return tab;
}

void	init_f_p(void)
{
	p[0] = check_user;
	p[1] = check_pass;
	p[2] = exec_pwd;
	p[3] = exec_cdup;
	p[4] = exec_cwd;
	p[5] = print_directory;
	p[6] = client_disconnect;
	p[7] = exec_help;
	p[8] = exec_dele;
	p[9] = exec_download;
	p[10] = exec_noop;
}
