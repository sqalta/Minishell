/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:28:23 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 21:40:44 by mkarakul         ###   ########.fr       */
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
		if (g_data.redirection[0] != NULL)
			exec_redir(status);
		else if (g_data.command[0] != NULL)
			exec_shell(status);
		exit(0);
		return ;
	}
	else
		wait(&status);
}
