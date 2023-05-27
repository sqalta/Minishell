/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:12:34 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/28 02:06:55 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_pipe(void)
{
	t_arg	*temp;

	temp = g_data.list;
	pipe(g_data.p_fd);
	g_data.pipe = fork();
	if (g_data.pipe == 0)
	{
		//
	}
	else
		wait(&g_data.pipe);
}
