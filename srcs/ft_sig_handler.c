/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:30:37 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/14 22:06:10 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		(void)sig;
		g_data.signal_status = -1;
		g_data.exit_status = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
	if (sig == SIGQUIT)
	{
		printf("ANAM\n");
	}
}
