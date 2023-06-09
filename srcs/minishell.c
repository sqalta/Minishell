/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/09 19:11:00 by mkarakul         ###   ########.fr       */
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
	t_arg	*tmp;

	tmp = NULL;
	while (1)
	{
		signal(SIGINT, ft_sig_handler);
		signal(SIGQUIT, ft_sig_handler);
		g_data.line = readline("minishell-$ ");
		ft_parse();
		temp = g_data.list;
		//getchar();
		//system("leaks minishell");
		add_history(g_data.line);
		free(g_data.line);
		if (error_check() == -1)
			continue ;
		if (g_data.count_type->heredoc > 0)
			ft_heredoc_line();
		if (g_data.count_type->dollar > 0)
			ft_dollars_line();
		if (ft_strcmp(g_data.list->arg, "exit"))
		{
			ft_exit(g_data.list);
			continue ;
		}
		if (initialize_pipe() == -1)
			execute();
		ft_free_all();
		while (temp)
		{
			tmp = temp;
			free(tmp->arg);
			free(tmp);
			temp = temp->next;
		}
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
