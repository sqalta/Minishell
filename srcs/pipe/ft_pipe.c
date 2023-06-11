/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:40:23 by mustafakara       #+#    #+#             */
/*   Updated: 2023/06/11 13:33:32 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_tubes(void)
{
	int	i;

	i = 0;
	g_data.all_pipe_fd = malloc(sizeof(int *) * (g_data.pipe_c));
	if (!g_data.all_pipe_fd)
		return ;
	while (i < g_data.pipe_c)
	{
		g_data.all_pipe_fd[i] = malloc(sizeof(int) * 2);
		pipe(g_data.all_pipe_fd[i]);
		i++;
	}
	//printf ("pipe sayısı: %d\n", i);
}

void	close_fd(int id)
{
	int	i;
	int	k;

	k = -1;
	i = -1;
	if (id == 0)
		while (++k < g_data.pipe_c)
		{
			while (++i != 2)
				if (!(i == 1 && k == 0))
					close(g_data.all_pipe_fd[k][i]);
			i = -1;
		}
	else if (id == g_data.pipe_c)
		while (++k < g_data.pipe_c)
		{
			while (++i != 2)
			{
				if (!(i == 0 && (k == g_data.pipe_c - 1)))
				{
					close(g_data.all_pipe_fd[k][i]);
				}
			}
			i = -1;
		}
	else
		while (++k < g_data.pipe_c)
		{
			while (++i != 2)
			{
				if (!(((i == 0 && k == id - 1)) || (i == 1 && k == id)))
				{
					close(g_data.all_pipe_fd[k][i]);
				}
			}
			i = -1;
		}
}

void	set_file_descriptor(int id) 
{
	if (id == 0)
	{
        //printf("firs id: %d\n", id);
		dup2(g_data.all_pipe_fd[id][1], 1);
		close_fd(id);
        //close(g_data.all_pipe_fd[id][0]);
		//close(g_data.all_pipe_fd[id + 1][1]);
		//close(g_data.all_pipe_fd[id + 1][0]);
		check_way();
	}
	else if (id == g_data.pipe_c)
	{
		//printf("last id: %d\n", id);
		dup2(g_data.all_pipe_fd[id - 1][0], 0);
		close_fd(id);
    	//close(g_data.all_pipe_fd[id - 1][1]);
    	//close(g_data.all_pipe_fd[id - 2][0]);
    	//close(g_data.all_pipe_fd[id - 2][1]);
		check_way();
	}
	else
	{
        //printf("mid id: %d\n", id);
		dup2(g_data.all_pipe_fd[id - 1][0], 0);
		dup2(g_data.all_pipe_fd[id][1], 1);
		close_fd(id);
		//close(g_data.all_pipe_fd[id][0]);
		//close(g_data.all_pipe_fd[id - 1][1]);
		check_way();
	}
}

void	ft_free_command_redirection()
{
	int	i;

	i = -1;
	while (g_data.command[++i])
		free(g_data.command[i]);
	free(g_data.command);
	i = -1;
	if (g_data.redirection)
	{
		while (g_data.redirection[++i])
			free(g_data.redirection[i]);
		free(g_data.redirection);
	}
	g_data.command = NULL;
	g_data.redirection = NULL;
}


void	initialize_fork(void)
{
	int	i;

	i = 0;
	g_data.pipe_id = malloc(sizeof(int) * (g_data.pipe_c + 1));
	while (i <= g_data.pipe_c)
	{
		if (i != 0)
			ft_free_command_redirection();
		ft_command_line();
		g_data.pipe_id[i] = fork();
		if (g_data.pipe_id[i] == 0)
			set_file_descriptor(i);
		else
			i++;
	}
	i = 0;
	int j = -1;
	int k = -1;
	while (++k != g_data.pipe_c)
	{
		while (++j != 2)
			close(g_data.all_pipe_fd[k][j]);
		j = -1;
	}
	while (i <= g_data.pipe_c)
	{
		waitpid(g_data.pipe_id[i], 0, 0);
		i++;
	}
	free(g_data.pipe_id);
	i = 0;
	while (i < g_data.pipe_c)
	{
		free(g_data.all_pipe_fd[i]);
		i++;
	}
	free(g_data.all_pipe_fd);
}

int	initialize_pipe(void)
{
	if (pipe_counter() == -1)
		return (-1);
	/*
	int i = 0;
	while (i <= g_data.pipe_c)
	{
		getchar();
		close_fd(i);
		i++;
	}
	exit (1);*/
	create_tubes();
	initialize_fork();
	return (0);
}