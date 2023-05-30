/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:12:34 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/30 16:28:13 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_pipe(void)
{
	int	count;

	count = 0;
	while (count <= g_data.pipe_c)
	{
		g_data.pipe[count] = fork();
		count++;
	}
	count = 0;
	if (g_data.pipe[count] == 0)
	{
		while (count < g_data.pipe_c)
		{
			ft_command_line();
			close(g_data.p_fd[1]);
			dup2(g_data.p_fd[0], 0);
			ft_execve();
			close(g_data.p_fd[0]);
		}
	}
	else
	{
		close(g_data.p_fd[0]);
		dup2(1, g_data.p_fd[1]);
		waitpid(g_data.pipe[count], &g_data.status, 0);
	}
}
