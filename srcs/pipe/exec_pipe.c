/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:12:34 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/29 02:49:45 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_pipe(void)
{
	int	count;

	count = 0;
	while (count < g_data.pipe_c)
	{
		g_data.pipe[count] = fork();
		count++;
	}
	count = 0;
	if (g_data.pipe[count] == 0)
	{
		while (count < g_data.pipe_c)
		{
			dup2(1, g_data.p_fd[1]);
			ft_execve();
			ft_command_line();
			close(g_data.p_fd[1]);
			count++;
		}
	}
	else
	{
		waitpid(g_data.pipe[count], &g_data.status, 0);
		count++;
	}
}
