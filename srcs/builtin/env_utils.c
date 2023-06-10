/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:05:32 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/10 17:08:38 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_ex_env_counter(void)
{
	int	i;

	i = 0;
	while (g_data.ex_path[i])
		i++;
	return (i);
}

void	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
}

char	**ft_addenv(int j)
{
	int		i;
	int		env_c;
	char	**tmp;
	char	*force;

	i = 0;
	env_c = ft_ex_env_counter();
	force = ft_strjoin(g_data.command[j], "=");
	tmp = (char **)malloc(sizeof(char *) * (env_c + 2));
	while (g_data.ex_path[i])
	{
		tmp[i] = g_data.ex_path[i];
		i++;
	}
	tmp[i] = force;
	tmp[i + 1] = NULL;
	free(g_data.ex_path);
	g_data.ex_path = tmp;
	return (tmp);
}

void	*ft_delenv(int i, int env_c)
{
	int		c;
	int		j;
	int		x;
	char	**tmp;

	c = 0;
	j = 0;
	x = ft_env_counter();
	tmp = (char **)malloc(sizeof(char *) * (x));
	while (g_data.envp[j])
	{
		if (j == i)
		{
			free(g_data.envp[j]);
			j++;
		}
		tmp[c] = g_data.envp[j];
		c++;
		j++;
	}
	tmp[c] = NULL;
	free(g_data.envp);
	g_data.envp = tmp;
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
