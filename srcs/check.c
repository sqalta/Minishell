/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:28:23 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/28 02:04:49 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_way(void)
{
	t_arg	*temp;
	int		status;

	temp = g_data.list;
	ft_command_line();
	if (builtin() == 0)
		return ;
	status = fork();
	if (status == 0)
	{
		if (g_data.redirection[0] != NULL)
			exec_redir(status);
		else if (g_data.command[0] != NULL)
			exec_shell(status);
		if (ft_strcmp(g_data.command[0], "echo"))
			ft_echo();
		if (!temp)
			exit(0);
	}
	else
		wait(&status);
}

void	check_way_loop(void)
{
	while (g_data.list != NULL)
	{
		ft_command_line();
		if (g_data.pipe_c > 0 && g_data.list)
			exec_pipe();
		else
			check_way();
		if (g_data.temp_list != NULL)
			g_data.list = g_data.temp_list->next;
		else
			break ;
	}
}
