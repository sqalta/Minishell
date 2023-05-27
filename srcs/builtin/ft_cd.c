/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:04:33 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/27 15:41:33 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_cd(void)
{
	if (g_data.command[1] && ft_strcmp(g_data.command[1], "~") == 0)
	{
		if (chdir(g_data.command[1]))
			perror("minishell ");
	}
	else if (chdir(getenv("HOME")))
		perror("minishell ");
}
