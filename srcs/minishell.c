/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/01 17:42:13 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_data g_data;

void	exec_shell(int status)
{
	if (status == 0)
		ft_execve();
	else
		perror("minishell");
}

void	start(void)
{
	t_arg	*temp;

	while (g_data.exit_status == 0)
	{
		g_data.line = readline("minishell-$ ");
		ft_parse();
		temp = g_data.list;
		if (!temp)
			continue ;
		if (ft_strcmp(temp->arg, "exit"))
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		g_data.deneme = 0;
		ft_heredoc_line();
		if (initialize_pipe() == -1)
			execute();
		add_history(g_data.line);
	}
}

int	main(int ac, char **av, char **envp)
{
	g_data.envp = envp;
	g_data.ex_path = envp;
	g_data.exit_status = 0;
	start();
}
