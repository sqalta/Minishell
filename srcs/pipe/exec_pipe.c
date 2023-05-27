/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:12:34 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/27 14:39:07 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_pipe(int status)
{
	t_arg	*temp;

	temp = g_data.list;
	pipe(g_data.p_fd);
	g_data.pipe = fork();
	if (g_data.pipe == 0)
	{
		dup2(g_data.p_fd[1], 1);
		close(g_data.p_fd[0]);
		exec_shell(status);
		exit(0);
	}
	else
	{
		wait(&status);
		dup2(g_data.p_fd[0], 0);
		close(g_data.p_fd[1]);
		exec_shell(status);
	}
}
