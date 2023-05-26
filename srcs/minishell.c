/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 19:33:36 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_data g_data;

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

	temp = NULL;
	while (1)
	{
		printf("\033[31m%s@\033[0m\033", get_username(g_data.envp));
		g_data.line = readline("[31mminishell-$> \033[0m");
		ft_parse();
		temp = g_data.list;
		if (!temp)
			continue ;
		if (ft_strcmp(temp->arg, "exit"))
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		check_way();
		add_history(g_data.line);
	}
}

int	main(int ac, char **av, char **envp)
{
	g_data.envp = envp;
	start();
}
