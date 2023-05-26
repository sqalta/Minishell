/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:40:14 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 19:18:05 by mkarakul         ###   ########.fr       */
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

int	ft_path_founder(char **envp, char *name, int len)
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
	int		i;
	int		env_c;
	t_arg	*temp;

	temp = g_data.list;
	if (!temp->next)
		return ;
	env_c = ft_env_counter();
	temp = temp->next;
	while (temp)
	{
		i = ft_path_founder(g_data.envp, temp->arg,
				ft_strlen(temp->arg));
		if (i != -1)
			ft_delenv(i, env_c);
		temp = temp->next;
	}
}
