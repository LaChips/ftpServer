##
## EPITECH PROJECT, 2018
## PSU_myftp_2017
## File description:
## Makefile
##

NAME	= server

CC	= gcc

RM	= rm -f

SRCS	= src/main.c \
	src/my_ftp.c \
	src/login_commands.c \
	src/logout_command.c \
	src/strtowordtab.c \
	src/file_commands.c \
	src/init_functions.c \
	src/info_commands.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
