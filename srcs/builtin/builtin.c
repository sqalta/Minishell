/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:34:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 19:12:29 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin(void)
{
	t_arg	*temp;

	temp = g_data.list;
	if (ft_strcmp(temp->arg, "echo"))
		ft_echo();
	else if (ft_strcmp(temp->arg, "cd"))
		ft_cd();
	else if (ft_strcmp(temp->arg, "pwd"))
		ft_pwd();
	else if (ft_strcmp(temp->arg, "export"))
		ft_export();
	else if (ft_strcmp(temp->arg, "unset"))
		ft_unset();
	else if (ft_strcmp(temp->arg, "env"))
		ft_env();
	else
		return (-1);
	return (0);
}
