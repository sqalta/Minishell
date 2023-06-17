/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollars_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:46:34 by mustafakara       #+#    #+#             */
/*   Updated: 2023/06/17 16:45:46 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_parse_dollars2(char **line, char *src)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i])
	{
		if (i == 0)
			src = ft_strdup(line[i]);
		else
		{
			temp = src;
			src = ft_strjoin(src, line[i]);
			free(temp);
		}
		free(line[i]);
		i++;
	}
	free(line);
	return (src);
}

void	ft_parse_dollars(void)
{
	char	*src;
	char	**line;
	int		i;

	i = 0;
	src = g_data.list->arg;
	line = ft_split(src, '$');
	free(src);
	while (line[i])
	{
		line[i] = ft_find_env(line[i]);
		i++;
	}
	src = ft_parse_dollars2(line, src);
	g_data.list->arg = src;
}

void	ft_dollars_line(void)
{
	t_arg	*temp_s;

	temp_s = g_data.list;
	while (g_data.list)
	{
		if (g_data.list->type == DOLLAR)
		{
			ft_parse_dollars();
		}
		g_data.list = g_data.list->next;
	}
	g_data.list = temp_s;
}
