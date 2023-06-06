/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:04:33 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/06 13:22:28 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd_changer(void)
{
	char	*str;
	int		i;

	i = 0;
	str = getcwd(NULL, 0);
	while (g_data.envp[i])
	{
		if (ft_strncmp(g_data.envp[i], "PWD=", 4) == 0)
		{
			g_data.envp[i] = ft_strjoin("PWD=", str);
			break ;
		}
		i++;
	}
	free(str);
}

void	ft_cd(void)
{
	if (g_data.command[1] && ft_strcmp(g_data.command[1], "~") == 0)
	{
		if (chdir(g_data.command[1]))
			perror("minishell ");
		ft_pwd_changer();
	}
	else if (chdir(getenv("HOME")))
		perror("minishell ");
}
