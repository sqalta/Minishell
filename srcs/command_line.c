/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:29:09 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/27 16:46:23 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_command_line(void)
{
	t_arg	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = g_data.list;
	g_data.command = malloc(1000000);
	g_data.redirection = malloc(1000000);
	while (temp && temp->type != PIPE)
	{
		if (temp->type == PIPE)
			g_data.pipe_c++;
		else if (temp->type == WORD)
			g_data.command[i++] = ft_strdup(temp->arg);
		else if (temp->type == OUTPUT_RDR || temp->type == INPUT_RDR)
		{
			g_data.redirection[j++] = ft_strdup(temp->arg);
			g_data.redirection[j++] = ft_strdup(temp->next->arg);
			temp = temp->next;
		}
		temp = temp->next;
	}
	g_data.list = temp;
	g_data.command[i] = NULL;
	g_data.redirection[j] = NULL;
}
