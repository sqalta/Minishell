/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:27:33 by mustafakara       #+#    #+#             */
/*   Updated: 2023/06/10 18:42:44 by spalta           ###   ########.fr       */
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
	int		len;
	char	*line;
	char	*ret;

	i = 0;
	line = line_connect(g_data.list);
	len = ft_strlen(line);
	free(line);
	while (g_data.envp[i])
	{
		if (ft_strncmp(line, g_data.envp[i], ft_strlen(line)) == 0)
		{
			ret = ft_strdup(g_data.envp[i] + len + 1);
			return (ret);
		}
		i++;
	}
	line = ft_strdup("");
	return (line);
}
