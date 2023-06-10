/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:28:23 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/10 19:12:38 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_way(void)
{
	int		status;

	status = 0;
	if (g_data.redirection != NULL)
		exec_redir(status);
	if (ft_strcmp(g_data.command[0], "export"))
	{
		if (g_data.command[1] == NULL)
			ft_export_path();
		else
			ft_export();
		exit(0);
	}
	else if (ft_strcmp(g_data.command[0], "echo"))
	{
		ft_echo();
		exit(0);
	}
	else if (g_data.command != NULL)
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
		check_way();
	else
		waitpid(status, NULL, 0);
}
