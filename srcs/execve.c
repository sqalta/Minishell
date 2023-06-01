/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:25:37 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/01 14:27:32 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	control_bin2(t_arg *temp, char *path, int j, char *dir)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (path[i])
	{
		j = i;
		while (path[j] && path[j] != ':')
			j++;
		dir = ft_substr(path, i, j - i);
		tmp = ft_strjoin(dir, "/");
		tmp = ft_strjoin(tmp, g_data.command[0]);
		if (access(tmp, F_OK) == 0)
		{
			g_data.command[0] = tmp;
			free(dir);
			return (1);
		}
		free(dir);
		free(tmp);
		i = j + 1;
	}
	return (0);
}

int	control_bin(void)
{
	int		i;
	int		j;
	char	*path;
	char	*dir;
	t_arg	*temp;

	temp = g_data.list;
	i = 0;
	if (ft_strncmp(g_data.command[0], "./", 2) == 0)
		return (1);
	while (g_data.envp[i])
	{
		if (ft_strncmp(g_data.envp[i], "PATH=", 5) == 0)
		{
			path = g_data.envp[i] + 5;
			break ;
		}
		else
			i++;
	}
	if (g_data.envp[i] == NULL)
		return (0);
	if (control_bin2(temp, path, j, dir))
		return (1);
	return (0);
}

void	ft_execve(void)
{
	t_arg	*temp;

	temp = g_data.list;
	if (control_bin())
		execve(g_data.command[0], g_data.command, g_data.envp);
	else
	{
		printf("minishell: %s: command not found\n", g_data.command[0]);
		exit(0);
	}
}
