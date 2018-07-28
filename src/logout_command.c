/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** logout_commands
*/

#include "my_ftp.h"

int	client_disconnect(char **tab, t_sock_info **info)
{
	(void)tab;
	(void)info;
	write((*info)->c_fd, MSG221, strlen(MSG221));
	return -1;
}
