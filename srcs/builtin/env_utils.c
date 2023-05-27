/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:05:32 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/27 15:40:42 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
}

char	**ft_addenv(void)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = malloc(sizeof(char **) * 100000);
	while (g_data.ex_path[i])
	{
		tmp[i] = g_data.ex_path[i];
		i++;
	}
	tmp[i] = g_data.command[1];
	g_data.ex_path = tmp;
	free(tmp);
	return (g_data.ex_path);
}

void	*ft_delenv(int i, int env_c)
{
	int		c;
	int		j;
	char	**tmp;

	c = 0;
	j = 0;
	tmp = malloc(sizeof(char **) * 100000);
	while (g_data.envp[j])
	{
		if (j == i)
			j++;
		tmp[c] = g_data.envp[j];
		c++;
		j++;
	}
	tmp[c] = NULL;
	g_data.envp = tmp;
	free(tmp);
	return (NULL);
}

void	*ft_getenv(char *name, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], name, ft_strlen(name)) == 0)
			return (args[i] + ft_strlen(name) + 1);
		i++;
	}
	return (NULL);
}

void	ft_env(void)
{
	int	i;

	i = 0;
	while (g_data.envp[i])
	{
		ft_putstr_fd(g_data.envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
