/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/05 18:23:09 by mustafakara      ###   ########.fr       */
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

	while (1)
	{
		g_data.line = readline("minishell-$ ");
		ft_parse();
		ft_heredoc_line();
		ft_dollars_line();
		if (error_check() == -1)
			continue ;
		temp = g_data.list;
		if (!temp)
			continue ;
		if (ft_strcmp(temp->arg, "exit"))
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		if (initialize_pipe() == -1)
			execute();
		add_history(g_data.line);
	}
}

void	ft_struct_initilaize(char **envp)
{
	g_data.envp = envp;
	g_data.ex_path = envp;
	g_data.exit_status = 0;
}

int	main(int ac, char **av, char **envp)
{
	ac = 0;
	av = NULL;
	ft_struct_initilaize(envp);
	start();
	return (0);
}
