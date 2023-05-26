/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:30:35 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/27 02:44:30 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "parse/parse.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <dirent.h>

typedef struct s_data
{
	char	**command;
	char	**redirection;
	char	**envp;
	char	**ex_path;
	int		fd;
	t_arg	*list;
	char	*line;
}	t_data;

t_data	g_data;

void	ft_initilaize(void);
int		ft_parse(void);
void	start(void);

void	ft_pwd(void);
char	**ft_addenv(void);
void	*ft_delenv(int i, int env_c);
void	*ft_getenv(char *name, char **args);
void	ft_env(void);
void	parsing_line(void);
void	all_free(void);

void	ft_echo(void);
void	ft_cd(void);
void	ft_export(void);
void	ft_unset(void);
int		builtin(void);

int		ft_strcmp(char *s1, char *s2);

void	check_way(void);
void	ft_execve(void);
void	exec_shell(int status);
void	ft_command_line(void);

void	exec_redir(int status);
void	exec_pipe(int status);

#endif