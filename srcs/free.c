/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:43:56 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/30 17:52:01 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	all_free(void)
{
	int	i;

	i = 0;
	while (g_data.command[i])
	{
		free(g_data.command[i]);
		i++;
	}
	i = 0;
	while (g_data.redirection[i])
	{
		free(g_data.redirection[i]);
		i++;
	}
	free (g_data.line);
}
