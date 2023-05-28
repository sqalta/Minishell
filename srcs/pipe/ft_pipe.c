/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:40:23 by mustafakara       #+#    #+#             */
/*   Updated: 2023/05/29 02:30:40 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    ft_pipe_init(void)
{
    g_data.output_fd = malloc(sizeof(int) * g_data.pipe_c);
    g_data.input_fd = malloc(sizeof(int) * g_data.pipe_c);
	g_data.pipe = malloc(sizeof(int) * g_data.pipe_c);
	g_data.fd_c = 0;
}

void	pipe_counter(void)
{
	t_arg	*temp;
	int		i;

	temp = g_data.list;
	i = 0;
	while (temp)
	{
		if (temp->type == PIPE)
			i++;
		temp = temp->next;
	}
	g_data.pipe_c = i;
    if (g_data.pipe_c > 0)
        ft_pipe_init();
}