/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** login_commands
*/

#include "my_ftp.h"

int	check_user(char **tab, t_sock_info **info)
{
	if (!tab[1])
		return 1;
	(*info)->user = 1;
	(*info)->login = strdup(tab[1]);
	write((*info)->c_fd, MSG331, strlen(MSG331));
	return 0;
}

int	check_pass(char **tab __attribute__((unused)),
t_sock_info **info)
{
	if ((*info)->user == 1) {
		if (strcmp((*info)->login, "Anonymous") == 0) {
			write((*info)->c_fd, MSG230, strlen(MSG230));
			(*info)->user = 0;
			(*info)->logged = 1;
		}
		else
			write((*info)->c_fd, MSG530, strlen(MSG530));
	}
	else
		write((*info)->c_fd, MSG332, strlen(MSG332));
	return 0;
}

int	exec_cdup(char **tab __attribute__((unused)),
t_sock_info **info)
{
	if (chdir("..") == 0)
		write((*info)->c_fd, MSG200, strlen(MSG200));
	else
		write((*info)->c_fd, MSG551, strlen(MSG551));
	return 0;
}

int	exec_cwd(char **tab, t_sock_info **info)
{
	if (chdir(tab[1]) == 0)
		write((*info)->c_fd, MSG250, strlen(MSG250));
	else
		write((*info)->c_fd, MSG551, strlen(MSG551));
	return 0;
}
