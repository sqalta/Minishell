/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/27 18:54:26 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_data g_data;

void	pipe_counter(void)
{
	t_arg	*temp;
	int		i;

	temp = g_data.list;
	i = 0;
	while (temp)
	{
		if (temp->type == PIPE)
			i++;
		temp = temp->next;
	}
	g_data.pipe_c = i;
}

char	*get_username(char **envp)
{
	char	*username;
	int		i;

	username = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "USER=", 5) == 0)
		{
			username = envp[i] + 5;
			break ;
		}
		i++;
	}
	return (username);
}

void	exec_shell(int status)
{
	if (status == 0)
		ft_execve();
	else
		perror("minishell");
}

void	start(void)
{
	t_arg	*temp;

	while (1)
	{
		g_data.line = readline("minishell-$ ");
		ft_parse();
		temp = g_data.list;
		if (!temp)
			continue ;
		if (ft_strcmp(temp->arg, "exit"))
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		pipe_counter();
		check_way_loop();
		add_history(g_data.line);
	}
}

int	main(int ac, char **av, char **envp)
{
	g_data.envp = envp;
	g_data.ex_path = envp;
	g_data.pipe_c = 0;
	start();
}
