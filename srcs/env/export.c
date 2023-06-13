/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:16:00 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/13 19:41:07 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*ft_export_path(void)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (g_data.ex_path[i])
	{
		j = 0;
		while (g_data.ex_path[i][j])
			j++;
		tmp = ft_substr(g_data.ex_path[i], 0, j);
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp, 1);
		ft_putstr_fd("\n", 1);
		free(tmp);
		i++;
	}
	return (NULL);
}

int	ft_env_controller(int j)
{
	int	i;

	i = 0;
	while (g_data.command[j][i] != '\0')
	{
		if (g_data.command[j][i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_export(void)
{
	int	j;

	j = 1;
	while (g_data.command[j])
	{
		if (ft_env_controller(j) == 1)
		{
			if (ft_path_founder(g_data.ex_path, g_data.command[j]) != -1)
				upenv(g_data.ex_path, j, 1);
			if (ft_path_founder(g_data.envp, g_data.command[j]) != -1)
				upenv(g_data.envp, j, 1);
			else
			{
				ft_addenv(g_data.envp, j, 0);
				ft_addenv(g_data.ex_path, j, 1);
			}
		}
		else
			ft_addenv(g_data.ex_path, j, 1);
		j++;
	}
}