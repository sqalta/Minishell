/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:58:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/12 21:36:46 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_heredoc_counter(void)
{
	t_arg	*temp;
	int		i;

	temp = g_data.list;
	i = 0;
	while (temp)
	{
		if (temp->type == DOUBLE_INPUT_RDR && temp->next)
			i++;
		temp = temp->next;
	}
	return (i);
}

void	ft_heredoc_start(int i)
{
	while (1)
	{
		g_data.here_line = readline("> ");
		if (ft_strcmp(g_data.here_line, g_data.heredoc[i]))
			break ;
		else
		{
			ft_putstr_fd(g_data.here_line, g_data.here_fd);
			ft_putstr_fd("\n", g_data.here_fd);
		}
	}
}

void	ft_heredoc(void)
{
	int	i;
	int	status;

	i = 0;
	g_data.here_fd = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (g_data.heredoc[i])
	{
		status = fork();
		if (status == 0)
		{
			ft_heredoc_start(i + 1);
			exit(0);
		}
		else
			waitpid(status, &g_data.exit_status, 0);
		i += 2;
	}
}

void	ft_heredoc_line(void)
{
	t_arg	*temp;
	int		i;
	int		j;

	temp = g_data.list;
	i = 0;
	j = ft_heredoc_counter();
	if (j > 0)
		g_data.heredoc = malloc(sizeof(char *) * (j * 2 + 1));
	while (temp)
	{
		if (temp->type == DOUBLE_INPUT_RDR && temp->next)
		{
			g_data.heredoc[i++] = ft_strdup(temp->arg);
			g_data.heredoc[i++] = ft_strdup(temp->next->arg);
		}
		temp = temp->next;
	}
	g_data.heredoc[i] = NULL;
	if (i > 0)
	{
		ft_heredoc();
	}
	else
		return ;
}
