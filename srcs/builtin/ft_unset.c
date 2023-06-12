/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:40:14 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/12 22:36:20 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_env_counter(void)
{
	int	i;

	i = 0;
	while (g_data.envp[i])
		i++;
	return (i);
}

int	env_founder(char *envp, char *name)
{
	int	i;

	i = 0;
	while (envp[i] == name[i])
		i++;
	if (envp[i] == '=')
		return (1);
	else
		return (0);
}

int	ft_path_founder(char **envp, char *name)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (env_founder(envp[i], name) == 1)
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_del_expath(int i)
{
	int		c;
	int		j;
	int		x;
	char	**tmp;

	c = 0;
	j = 0;
	x = ft_env_counter();
	tmp = (char **)malloc(sizeof(char *) * (x));
	while (g_data.ex_path[j])
	{
		if (j == i)
		{
			free(g_data.ex_path[j]);
			j++;
		}
		tmp[c] = g_data.ex_path[j];
		c++;
		j++;
	}
	tmp[c] = NULL;
	free(g_data.ex_path);
	g_data.ex_path = tmp;
	return (NULL);
}

void	ft_unset(void)
{
	int		i;
	int		j;
	int		env_c;

	j = 1;
	if (g_data.command[j] == NULL)
		return ;
	while (g_data.command[j])
	{
		i = ft_path_founder(g_data.envp, g_data.command[j]);
		if (i != -1)
			ft_delenv(i);
		j++;
	}
	j = 1;
	if (g_data.command[j] == NULL)
		return ;
	while (g_data.command[j])
	{
		i = ft_path_founder(g_data.ex_path, g_data.command[j]);
		if (i != -1)
			ft_del_expath(i);
		j++;
	}
}
