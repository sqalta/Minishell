/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:20:57 by spalta            #+#    #+#             */
/*   Updated: 2023/06/06 16:11:08 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

void	print_list(t_arg *lst)
{
	while (lst->next)
	{
		printf ("%s\n", lst->arg);
		lst = lst->next;
	}
	printf ("%s\n", lst->arg);
}

void	tokenizer(t_arg **prompt)
{
	split_by_space(g_data.line, prompt);
	split_by_redirection(prompt);
	split_by_pipe(prompt);
}

int	ft_parse(void)
{
	t_arg	*line;

	line = ft_calloc(1, sizeof(t_arg));
	tokenizer(&line);
	identify_token(&line);
	quot_cleaner(&line);
	g_data.list = line;
	return (1);
}
