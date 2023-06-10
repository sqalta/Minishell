/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:41:07 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/10 18:27:02 by spalta           ###   ########.fr       */
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
			ft_put_env_export(j);
		else
			ft_addenv(j);
		j++;
	}	
}
void	free_expath_envp()
{
	int	i;

	i = 0;
	while (g_data.envp[i])
		free(g_data.envp[i++]);
	free(g_data.envp);
	i = 0;
	while (g_data.ex_path[i])
		free(g_data.ex_path[i++]);
	free(g_data.ex_path);
}

void	ft_put_env_export(int j)
{
	int		i;
	char	*force;
	char	**temp;
	int		count;

	i = 0;
	count = ft_env_counter();
	force = ft_strjoin(g_data.command[j], "\0");
	temp = malloc(sizeof(char *) * (count + 2));
	while (g_data.envp[i])
	{
		if (i == 0)
			temp[i] = force;
		else
			temp[i] = ft_strdup(g_data.envp[i - 1]);
		i++;
	}
	temp[i] = NULL;
	free_expath_envp();
	g_data.envp = temp;
	g_data.ex_path = g_data.envp;
}
