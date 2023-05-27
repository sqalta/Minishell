/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:28:23 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/27 15:07:21 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_way(void)
{
	t_arg	*temp;
	int		status;

	temp = g_data.list;
	ft_command_line();
	if (builtin() != -1)
		return ;
	status = fork();
	if (status == 0)
	{
		if (g_data.pipe >= 1)
			exec_pipe(status);
		if (g_data.redirection[0] != NULL)
			exec_redir(status);
		else if (g_data.command[0] != NULL)
			exec_shell(status);
		if (ft_strcmp(g_data.command[0], "echo"))
			ft_echo();
		else
			printf("minishell: syntax error near unexpected token %s",
				g_data.command[0]);
		exit(0);
		return ;
	}
	else
		wait(&status);
}
