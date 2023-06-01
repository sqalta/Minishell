/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:58:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/01 14:28:30 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_heredoc(void)
{
	char	**heredoc;
	int		i;

	heredoc = g_data.heredoc;
	i = 0;
	while (heredoc[i])
	{
		if (ft_strcmp(heredoc[i], "<<"))
			ft_putstr_fd(heredoc[i + 1], 1);
		else if (ft_strcmp(heredoc[i], ">>"))
			ft_putstr_fd(heredoc[i + 1], 1);
		i += 2;
	}
}
