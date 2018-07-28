/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** main
*/

#include "my_ftp.h"

void	print_help(void)
{
	printf("USAGE: ./server port path\n\tport\t\
is the port number on which the server socket listens\n	\
path\tis the path to the home directory for the \
Anonymous user\n");
}

int	check_help(char **av)
{
	if (av[1] && strcmp(av[1], "-help") != 0)
		return 1;
	print_help();
	return 0;
}

int	check_params(char **av)
{
	if (atoi(av[1]) == 0)
		return 0;
	return 1;
}

int	main(int ac, char **av)
{
	if (ac != 3) {
		if (check_help(av) == 0)
			return 84;
		return 0;
	}
	if (check_params(av) == 0)
		return 84;
	launch_ftp(av);
	return 0;
}
