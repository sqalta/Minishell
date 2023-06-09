/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:49:17 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/09 19:43:57 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	error_msg(int flag, t_arg *temp)
{
	char	*str;

	if (flag == 1)
	{
		if (temp->next == NULL)
			str = ft_strdup("newline");
		else
			str = ft_strdup(temp->next->arg);
		printf("minishell: syntax error near unexpected token '%s'\n", str);
		free(str);
		return (-1);
	}
	else
		return (0);
}

int	error_check(void)
{
	int		flag;
	t_arg	*temp;

	temp = g_data.list;
	flag = 0;
	if (!temp)
		return (-1);
	if (temp->type == PIPE)
	{
		error_msg(1, temp);
		return (-1);
	}
	while (temp)
	{
		if (temp->type == PIPE)
		{
			if (temp->next == NULL)
			{
				flag = 1;
				break ;
			}
		}
		else if (temp->type == INPUT_RDR || temp->type == OUTPUT_RDR
			|| temp->type == DOUBLE_INPUT_RDR
			|| temp->type == DOUBLE_OUTPUT_RDR)
		{
			if (temp->next == NULL || temp->next->type != WORD)
			{
				flag = 1;
				break ;
			}
		}
		temp = temp->next;
	}
	if (error_msg(flag, temp) == -1)
		return (-1);
	return (0);
}
