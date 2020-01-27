/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:49:59 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 19:25:39 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		check_token1(char *s, int size)
{
	if ((size == 1) && (s[0] == ';' || s[0] == '\n'))
		return (3);
	else if (size == 1 && s[0] == '|')
		return (4);
	else if (size > 1 && s[0] == s[1])
	{
		if (s[0] == '|')
			return (8);
		else if (s[0] == '&')
			return (9);
	}
	else if (size > 1 && s[0] != s[1])
	{
		if (s[0] == '<' && s[1] == '>')
			return (12);
	}
	return (0);
}

int		check_type(int size_token, char *str)
{
	int	ret;

	ret = 0;
	if (size_token == 1 && (*str == '|' || *str == '&' || *str == ';' ||
		*str == '\n' || *str == '~' || *str == '.'))
		ret = check_token1(str, size_token);
	else if (size_token > 1 && (*str == '|' || *str == '&' || *str == '.'))
		ret = check_token1(str, size_token);
	else if (*str == '"' || *str == '\'' || *str == '`')
		ret = 17;
	else
		ret = 0;
	return (ret);
}

t_token	*creat_token(char *str, int s, char *tmp)
{
	t_token	*t;

	tmp = create_content(ft_strndup(str, s), 0, 0);
	t = (t_token *)malloc(sizeof(t_token));
	if (!check_token3(&t, tmp, (int)ft_strlen(tmp), 0))
	{
		t->type = check_type((int)ft_strlen(tmp), tmp);
		if (*tmp == '~')
			t->content = ft_strjoin(ft_get_env_var("HOME="), tmp + 1);
		else
			t->content = ft_strdup(tmp);
	}
	ft_strdel(&tmp);
	t->sel = 0;
	t->prev = NULL;
	t->next = NULL;
	return (t);
}
