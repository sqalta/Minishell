/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:34:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/27 02:58:58 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin(void)
{
	if (g_data.command[0] == NULL)
		return (-1);
	if (ft_strcmp(g_data.command[0], "cd"))
		ft_cd();
	else if (ft_strcmp(g_data.command[0], "pwd"))
		ft_pwd();
	else if (ft_strcmp(g_data.command[0], "export"))
		ft_export();
	else if (ft_strcmp(g_data.command[0], "unset"))
		ft_unset();
	else if (ft_strcmp(g_data.command[0], "env"))
		ft_env();
	else
		return (-1);
	return (0);
}
