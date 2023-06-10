/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/10 18:57:44 by spalta           ###   ########.fr       */
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

void	freeliazer(t_arg *tmp, t_arg *temp)
{
	ft_free_all();
	if (temp)
	{
		while (temp)
		{
			tmp = temp;
			free(tmp->arg);
			free(tmp);
			temp = temp->next;
		}
	}
}

char	**create_cpy_env(char **envp)
{
	int		i;
	char	**cpy_env;

	i = 0;
	while (envp[i])
		i++;
	cpy_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		cpy_env[i] = ft_strdup(envp[i]);
		i++;
	}
	cpy_env[i] = NULL;
	return (cpy_env);
}

void	ft_struct_initilaize(char **envp, int flag)
{
	if (flag)
	{
		g_data.ex_path = create_cpy_env(envp);
		g_data.envp = create_cpy_env(envp);
	}
	g_data.exit_status = 0;
	g_data.list = NULL;
	g_data.command = NULL;
	g_data.redirection = NULL;
	g_data.count_type = NULL;
	g_data.heredoc = NULL;
	g_data.line = NULL;
}

void	start(void)
{
	t_arg	*temp;
	t_arg	*tmp;

	tmp = NULL;
	while (1)
	{
		ft_struct_initilaize(g_data.envp, 0);
		signal(SIGINT, ft_sig_handler);
		signal(SIGQUIT, ft_sig_handler);
		g_data.line = readline("minishell-$ ");
		ft_parse();
		if (g_data.count_type->dollar > 0)
			ft_dollars_line();
		temp = g_data.list;
		add_history(g_data.line);
		free(g_data.line);
		if (error_check() == -1)
		{
			temp = NULL;
			freeliazer(tmp, temp);
			continue ;
		}
		if (g_data.count_type->heredoc > 0)
			ft_heredoc_line();
		if (ft_strcmp(g_data.list->arg, "exit"))
		{
			ft_exit(g_data.list);
			continue ;
		}
		if (initialize_pipe() == -1)
			execute();
		freeliazer(tmp, temp);
	}
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
	ft_struct_initilaize(envp, 1);
	start();
	return (0);
}
