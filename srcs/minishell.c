/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/07 18:31:35 by mustafakara      ###   ########.fr       */
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
		if (error_check() == -1)
			continue ;
		ft_heredoc_line();
		ft_dollars_line();
		temp = g_data.list;
		if (ft_strcmp(temp->arg, "exit"))
		{
			ft_exit(g_data.list);
			continue ;
		}
		if (initialize_pipe() == -1)
		{
			execute();
		}
		add_history(g_data.line);
		ft_free_all();
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
	if (ac > 1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
	av = NULL;
	ft_struct_initilaize(envp);
	start();
	return (0);
}
