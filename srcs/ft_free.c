/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:12:24 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/06 19:13:31 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_all(void)
{
	int	i;

	i = 0;
	while (g_data.command[i])
	{
		free(g_data.command[i]);
		i++;
	}
	free(g_data.command);
	i = 0;
	while (g_data.redirection[i])
	{
		free(g_data.redirection[i]);
		i++;
	}
	free(g_data.redirection);
}
