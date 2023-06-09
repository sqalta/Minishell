/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:12:24 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/09 19:14:56 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_all(void)
{
	int	i;

	while (g_data.list)
	{
		free(g_data.list->arg);
		g_data.list = g_data.list->next;
	}
	free(g_data.list);
	i = 0;
	if (g_data.command)
	{
		while (g_data.command[i])
			free(g_data.command[i++]);
		free(g_data.command);
	}
	i = 0;
	if (g_data.redirection)
	{
		while (g_data.redirection[i])
			free(g_data.redirection[i++]);
		free(g_data.redirection);
	}
	if (g_data.count_type)
		free(g_data.count_type);
	i = 0;
	if (g_data.heredoc)
	{
		while (g_data.heredoc[i])
			free(g_data.heredoc[i++]);
		free(g_data.heredoc);
	}
}
