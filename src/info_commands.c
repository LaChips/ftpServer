/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** info_commands
*/

#include "my_ftp.h"

int	exec_help(char **tab __attribute__ ((unused)),
t_sock_info **i)
{
	write((*i)->c_fd, MSG214, strlen(MSG214));
	return 0;
}

int	exec_noop(char **tab __attribute__ ((unused)),
t_sock_info **i)
{
	write((*i)->c_fd, MSG200, strlen(MSG200));
	return 0;
}
