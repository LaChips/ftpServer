/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** my_ftp
*/

#ifndef MY_FTP_H_
# define MY_FTP_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <dirent.h>
# include "messages.h"
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_sock_info
{
	char			*c_ip;
	struct sockaddr_in	c_s_in;
	struct protoent		*p;
	struct sockaddr_in	s_in;
	socklen_t		s_in_size;
	char			*login;
	int			c_fd;
	int			s_fd;
	int			user;
	int			logged;
}				t_sock_info;

int	check_user(char **, t_sock_info **);
int	check_pass(char **, t_sock_info **);
int	exec_cwd(char **, t_sock_info **);
int	exec_cdup(char **, t_sock_info **);
int	client_disconnect(char **, t_sock_info **);
int	exec_pwd(char **, t_sock_info **);
int	print_directory(char **, t_sock_info **);
int	exec_help(char **, t_sock_info **);
int	exec_cdup(char **, t_sock_info **);
int	exec_dele();
int	exec_download();
int	exec_noop();

int	(*p[11])(char **tab, t_sock_info **);

int	launch_ftp(char **);
char	**parse_command(char *);
char	**init_cmd(void);
void	init_f_p(void);
int	find_command(char **, char **, t_sock_info *);

#endif /* MY_FTP_H_ */
