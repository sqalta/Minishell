/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:28:23 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 19:31:12 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_way(void)
{
	t_arg	*temp;
	int		status;

	temp = g_data.list;
	ft_command_line();
	if (builtin() != -1)
		return (0);
	status = fork();
	if (temp && status == 0)
	{
		if (temp->type == WORD)
			exec_shell(status);
		exit(0);
		return (0);
	}
	else
		wait(&status);
}
