/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:27:53 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/13 17:42:55 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	env_founder(char *envp, char *name)
{
	int	i;

	i = 0;
	while (envp[i] == name[i])
		i++;
	if (envp[i] == '=' || envp[i] == '\0')
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

void	ft_unset(void)
{
	int	i;
	int	j;
	int	l;
	int	env_c;

	j = 1;
	if (g_data.command[j] == NULL)
		return ;
	while (g_data.command[j])
	{
		i = ft_path_founder(g_data.envp, g_data.command[j]);
		l = ft_path_founder(g_data.ex_path, g_data.command[j]);
		getchar();
		printf ("i=%d\nl=%d\n", i, l);
		if (i != -1)
			ft_delenv(g_data.envp, i, 0);
		if (l != -1)
			ft_delenv(g_data.ex_path, l, 1);
		j++;
	}
}
