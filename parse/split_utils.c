/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serif <serif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:46:10 by serif             #+#    #+#             */
/*   Updated: 2023/06/05 17:07:40 by serif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"
int check_quotation(char *s)
{
	char	handle;
	int		i;
	int		len;

	handle = '\"';
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == handle)
			len++;
		i++;
	}
	if (len % 2)
		exit(1); //EXİT DEĞİŞTİR !!!
	else
		return (len);
}
int		calculate_new_arg_len(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			while (s[++i] != '\"')
				len++;
		else if (s[i] == '\'')
			while (s[++i] != '\'')
				len++;
		else
			len++;
		i++;
	}
	return (len);
}

char	*trim_quot(char *s)
{
	int		len;
	char	*new;
	int		i;
	int		j;
	int		flag;
	
	len = calculate_new_arg_len(s);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			while (s[++i] != '\"')
				new[j++] = s[i];
		else if (s[i] == '\'')
			while (s[++i] != '\'')
				new[j++] = s[i];
		else
			new[j++] = s[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}

int	contains_quot(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_quotation(&s[i]))
			return (1);
		i++;
	}
	return (0);
}

void	quot_cleaner(t_arg	**prompt)
{
	t_arg	*iter;
	char	*s;

	iter = *prompt;
	while (iter)
	{
		if (contains_quot(iter->arg))
			if (iter->type != DOLLAR)
			{
				s = iter->arg;
				iter->arg = trim_quot(iter->arg);
				free(s);
			}
		iter = iter->next;
	}
}