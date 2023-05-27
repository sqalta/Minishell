/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:12:34 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/27 19:09:52 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_pipe(void)
{
	t_arg	*temp;

	temp = g_data.list;
	pipe(g_data.p_fd);
	g_data.pipe = fork();
	if (1 == 1)
	{
		dup2(1, g_data.p_fd[1]);
		exec_shell(g_data.pipe);
		close(g_data.p_fd[0]);
	}
	else
	{
		printf("AAAAAA\n");
		exit(0);
		//wait(&g_data.pipe);
		//exit (1);
		//dup2(0, g_data.p_fd[1]);
		//close(g_data.p_fd[1]);
		//exec_shell(g_data.pipe);
	}
}
