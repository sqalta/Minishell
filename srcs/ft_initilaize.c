/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initilaize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:02:10 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 17:24:41 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_global *g_data;

void	ft_initilaize(void)
{
	g_data->fd = 5;
	printf("%d", g_data->fd);
}
