/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:40:23 by mustafakara       #+#    #+#             */
/*   Updated: 2023/06/01 17:39:16 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_tubes(void)
{
	int	i;

	i = -1;
	g_data.all_pipe_fd = malloc(sizeof(int *) * g_data.pipe_c);
	if (!g_data.all_pipe_fd)
		return ;
	while (++i < g_data.pipe_c)
	{
		g_data.all_pipe_fd[i] = malloc(sizeof(int) * 2);
		pipe(g_data.all_pipe_fd[i]);
	}
}

void	set_file_descriptor(int id)
{
	if (id == 0 || id % 2 == 0)
	{
		printf("İLK GİRDİ\n");
		dup2(g_data.all_pipe_fd[0][1], 1);
		close(g_data.all_pipe_fd[0][0]);
		check_way();
	}
	else
	{
		printf("İKİNCİ GİRDİ\n");
		dup2(g_data.all_pipe_fd[0][0], 0);
		close(g_data.all_pipe_fd[0][1]);
		check_way();
	}
}

void	initialize_fork(void)
{
	int	i;

	i = 0;
	g_data.pipe_id = malloc(sizeof(int) * g_data.pipe_c + 1);
	while (i <= g_data.pipe_c)
	{
		ft_command_line();
		g_data.pipe_id[i] = fork();
		if (g_data.pipe_id[i] == 0)
			set_file_descriptor(i);
		i++;
	}
	i = 0;
	close(g_data.all_pipe_fd[0][1]);
	close(g_data.all_pipe_fd[0][0]);
	while (i <= g_data.pipe_c)
	{
		waitpid(g_data.pipe_id[i], 0, 0);
		i++;
	}
}

int	initialize_pipe(void)
{
	if (pipe_counter() == -1)
		return (-1);
	create_tubes();
	initialize_fork();
	return (0);
}
