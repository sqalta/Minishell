/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:28:23 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/07 22:17:58 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_way(void)
{
	int		status;

	status = 0;
	if (g_data.redirection[0] != NULL)
		exec_redir(status);
	else if (g_data.command[0][0] == '\0')
	{
		printf("minishell: %s: command not found\n", g_data.command[0]);
		exit(127);
	}
	else if (g_data.command[0] != NULL)
		ft_execve();
}

void	execute(void)
{
	int	status;

	ft_command_line();
	if (builtin() == -1)
		status = fork();
	else
		return ;
	if (status == 0)
	{
		if (ft_strcmp(g_data.command[0], "export"))
		{
			ft_export_path();
			exit(0);
		}
		else if (ft_strcmp(g_data.command[0], "echo"))
		{
			ft_echo();
			exit(0);
		}
		else
			check_way();
	}
	else
		waitpid(status, NULL, 0);
}
