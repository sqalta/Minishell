/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:29:09 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 19:30:36 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_command_line(void)
{
	t_arg	*temp;
	int		i;

	i = 0;
	temp = g_data.list;
	g_data.command = malloc(sizeof(char *) * 100000);
	while (temp)
	{
		g_data.command[i++] = temp->arg;
		temp = temp->next;
	}
}
