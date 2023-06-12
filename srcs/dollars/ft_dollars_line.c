/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollars_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:46:34 by mustafakara       #+#    #+#             */
/*   Updated: 2023/06/12 16:47:23 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*found_array(int start, int end, char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		temp[i] = str[start];
		i++;
		start++;
	}
	temp[i] = '\0';
	return (temp);
}

void	ft_parse_dollars(void)
{
	char	*line;
	char	*line2;
	char	*line3;
	int		i;
	int		j;

	i = 0;
	while (g_data.list->arg[i] != '$')
		i++;
	line = found_array(0, i, g_data.list->arg);
	i++;
	j = i;
	while (ft_isalnum(g_data.list->arg[i]) || ft_isalpha(g_data.list->arg[i]))
		i++;
	line2 = found_array(j, i, g_data.list->arg);
	line2 = ft_find_env(line2);
	line3 = ft_strjoin(line, line2);
	free(line);
	free(line2);
	free(g_data.list->arg);
	g_data.list->arg = line3;
}

void	ft_dollars_line(void)
{
	t_arg	*temp_s;

	temp_s = g_data.list;
	while (g_data.list)
	{
		if (g_data.list->type == DOLLAR)
			ft_parse_dollars();
		g_data.list = g_data.list->next;
	}
	g_data.list = temp_s;
}
