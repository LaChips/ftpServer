/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** my_ftp
*/

#include "my_ftp.h"

int		find_command(char **str, char **cmd,
			     t_sock_info *in)
{
	int	i;

	for (i = 0; cmd[i]; i++)
		if (strcmp(str[0], cmd[i]) == 0 &&
			(i < 2 || in->logged == 1) &&
			(*p[i])(str, &in) != -1)
			return 0;
	return 1;
}

void		handle_msg(t_sock_info *in)
{
	char	buffer[256];
	int	command_exist;
	char	**cmd = init_cmd();

	memset(buffer, 0, 256);
	init_f_p();
	while (read(in->c_fd, buffer, 256) > 0) {
		buffer[strlen(buffer)] = '\0';
		if (buffer[0] == '\0' || buffer[0] == '\r')
			return;
		char	**str = parse_command((char *)buffer);
		command_exist = find_command(str, cmd, in);
		if ((in->user == 0 && in->logged == 0))
			write(in->c_fd, MSG530, strlen(MSG530));
		else if (command_exist == 1 && in->logged == 1 &&
			 strcmp(str[0], "QUIT") != 0)
			write(in->c_fd, MSG500, strlen(MSG500));
		memset(buffer, 0, 256);
	}
}

void			listen_for_client(t_sock_info *info)
{
	while (1) {
		info->c_fd = accept(info->s_fd,
				    (struct sockaddr *)&info->c_s_in,
				    &info->s_in_size);
		if (info->c_fd != -1) {
			int	ret = fork();
			if (ret == 0) {
				write(info->c_fd, MSG220, strlen(MSG220));
				info->c_ip = inet_ntoa(info->c_s_in.sin_addr);
				handle_msg(info);
				close(info->c_fd);
			}
			else if (ret == -1) {
				close(info->c_fd);
				exit(84);
			}
		}
		else
			close(info->c_fd);
	}
}

int			init_socket(t_sock_info *infos,
char *port)
{
	infos->s_in_size = sizeof(infos->c_s_in);
	infos->p = getprotobyname("TCP");
	infos->s_fd = socket(AF_INET, SOCK_STREAM, infos->p->p_proto);
	if (infos->s_fd == -1)
		return -1;
	infos->s_in.sin_family = AF_INET;
	infos->s_in.sin_port = htons(atoi(port));
	infos->s_in.sin_addr.s_addr = INADDR_ANY;
	infos->user = 0;
	infos->logged = 0;
	if (bind(infos->s_fd,
		(const struct sockaddr *)&infos->s_in,
		sizeof(infos->s_in)) == -1)
		return -1;
	if (listen(infos->s_fd, 42) == -1)
		return -1;
	return 0;
}

int			launch_ftp(char **av)
{
	t_sock_info	infos;

	init_socket(&infos, av[1]);
	chdir(av[2]);
	if (infos.s_fd == -1) {
		fprintf(stderr, "Error occured while initializing socket");
		return 1;
	}
	listen_for_client(&infos);
	close(infos.s_fd);
	return 0;
}
