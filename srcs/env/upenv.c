/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:14:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/13 18:34:25 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	upenv(char **envp, int j, int flag)
{
	int		i;
	int		l;
	char	*force;

	i = 0;
	force = ft_strdup(g_data.command[j]);
	l = ft_path_founder(envp, g_data.command[j]);
	if (l != -1)
	{
		free(envp[l]);
		if (!flag)
			g_data.envp[l] = force;
		else
			g_data.ex_path[l] = force;
	}
	else
		return ;
}
