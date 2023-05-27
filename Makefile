# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 18:58:37 by mkarakul          #+#    #+#              #
#    Updated: 2023/05/28 02:01:47 by mustafakara      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

m = default commit message

NAME = minishell

LIBFT_S = cd libft && make

LIBFT_C = cd libft && make fclean

SRC = libft/libft.a srcs/utils/ft_strcmp.c srcs/minishell.c \
	lexer/*.c parse/*.c srcs/builtin/builtin.c srcs/builtin/env_utils.c \
	srcs/builtin/ft_cd.c srcs/builtin/ft_echo.c srcs/builtin/ft_export.c \
	srcs/builtin/ft_unset.c srcs/execve.c srcs/check.c srcs/command_line.c \
	srcs/redir/exec_redir.c srcs/pipe/exec_pipe.c srcs/pipe/ft_pipe.c \

GCC = gcc -g

FLAG = -lreadline -o $(NAME)

all:
	$(LIBFT_S)
	$(GCC) $(SRC) $(FLAG)

clean:
	rm -rf $(NAME)

git:
	git add .
	git status
	git commit -m "$(m)"
	git push
