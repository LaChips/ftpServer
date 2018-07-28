/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** file_commands
*/

#include "my_ftp.h"

int		exec_pwd(char **tab __attribute__((unused)),
t_sock_info **i)
{
	char	cwd[256];

	if (chdir(".") != 0)
		perror("chdir() error()");
	else {
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			perror("getcwd() error");
		else {
			write((*i)->c_fd, MSG257, strlen(MSG257));
			write((*i)->c_fd, &cwd, strlen(cwd));
			write((*i)->c_fd, MSG258, strlen(MSG258));
		}
	}
	return 0;
}

int			print_directory(char **tab, t_sock_info **info)
{
	DIR		*d;
	struct dirent	*dir;

	d = opendir(".");
	if (tab[1]) {
		closedir(d);
		d = opendir(tab[1]);
	}
	if (d) {
		write((*info)->c_fd, MSG150, strlen(MSG150));
		for (dir = readdir(d); dir != NULL; dir = readdir(d)) {
			write((*info)->c_fd, &dir->d_name,
			strlen(dir->d_name));
			write((*info)->c_fd, "\n", 1);
		}
		write((*info)->c_fd, MSG226, strlen(MSG226));
		closedir(d);
	}
	return 1;
}

int		exec_dele(char **tab, t_sock_info **info)
{
	int	ret;

	if (!tab[1])
		return 84;
	ret = remove(tab[1]);
	if (ret == 0)
		write((*info)->c_fd, MSG250, strlen(MSG250));
	else
		write((*info)->c_fd, MSGERR, strlen(MSGERR));
	return ret;
}

int			exec_download(char **tab, t_sock_info **info)
{
	int		fd;
	struct stat	f_stat;
	char		buf[2];
	int		i;

	if (!tab[1])
		return 1;
	fd = open(tab[1], O_RDONLY);
	if (fd == -1 || fstat(fd, &f_stat) < 0) {
		write((*info)->c_fd, MSGERR, strlen(MSGERR));
		return 1;
	}
	write((*info)->c_fd, MSG150, strlen(MSG150));
	for (i = 0; i < f_stat.st_size; i++) {
		if (read(fd, (char *)buf, 1) >= 0)
			write((*info)->c_fd, &buf[0], 1);
	}
	write((*info)->c_fd, MSG226, strlen(MSG226));
	return 0;
}
