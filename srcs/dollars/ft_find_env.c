/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:27:33 by mustafakara       #+#    #+#             */
/*   Updated: 2023/06/10 17:11:03 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*line_connect(t_arg *list)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 1;
	line = malloc(sizeof(char) * (ft_strlen(list->arg)));
	while (list->arg[j])
	{
		line[i] = list->arg[j];
		i++;
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_find_env(char *arg)
{
	int		i;
	char	**envp;
	char	*line;

	i = 0;
	envp = g_data.envp;
	line = line_connect(g_data.list);
	while (envp[i])
	{
		if (ft_strncmp(line, envp[i], ft_strlen(line)) == 0)
		{
			line = ft_strdup(envp[i] + ft_strlen(line) + 1);
			return (line);
		}
		i++;
	}
	line = ft_strdup("");
	return (line);
}
