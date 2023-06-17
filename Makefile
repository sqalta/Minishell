# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: serif <serif@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 18:58:37 by mkarakul          #+#    #+#              #
#    Updated: 2023/06/17 18:08:55 by serif            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

m = default commit message

NAME = minishell

LIBFT = libft/libft.a

LIBFT_S = cd libft && make

SRC = srcs/utils/ft_strcmp.c srcs/minishell.c \
	lexer/*.c parse/*.c srcs/builtin/builtin.c srcs/env/env_counter.c \
	srcs/builtin/ft_cd.c srcs/builtin/ft_echo.c srcs/env/export.c \
	srcs/env/unset.c srcs/execve.c srcs/execute.c srcs/command_line.c \
	srcs/redir/exec_redir.c srcs/pipe/exec_pipe.c srcs/pipe/ft_pipe.c \
	srcs/heredoc/exec_heredoc.c srcs/error_msg.c srcs/dollars/ft_dollars_line.c \
	srcs/dollars/ft_find_env.c srcs/ft_exit.c srcs/ft_free.c srcs/ft_sig_handler.c \
	srcs/env/addenv.c srcs/env/delenv.c srcs/env/env_utils.c srcs/env/upenv.c

CC = gcc -g #-fsanitize=address
FLAG = -lreadline -o $(NAME)

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(FLAG) $(SRC) $(LIBFT)

$(LIBFT):
	$(LIBFT_S)

clean:
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	cd libft/ && rm -rf *.o

fclean: clean

re:	fclean all

git:
	git add .
	git status
	git commit -m "$(m)"
	git push
