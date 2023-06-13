/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:13:16 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/13 14:27:47 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_delenv(char **envp, int j)
{
	int		i;
	char	**new_envp;

	i = 0;
	new_envp = (char **)malloc(sizeof(char *) * (env_counter(envp)));
	while (envp[i])
	{
		if (i == j)
		{
			free(envp[i]);
			i++;
		}
		else
		{
			new_envp[i] = envp[i];
			i++;
		}
	}
	new_envp[i] = NULL;
	free(envp);
	envp = new_envp;
}
