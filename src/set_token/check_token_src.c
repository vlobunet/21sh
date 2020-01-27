/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_src.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:28:18 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 19:28:20 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	set_tok1(char *c, t_token **t)
{
	if (c[1] == c[2] && (c[1] == '<' || c[1] == '>'))
		(*t)->type = (c[1] == '>' ? 21 : 22);
	else if (c[1] == '>' || c[1] == '<')
		(*t)->type = (c[1] == '>' ? 19 : 20);
	(*t)->content = ft_strdup("&");
}

void	set_tok(char *c, t_token **t, int i)
{
	if ((c[i] == '>' || c[i] == '<') && c[i + 1] == '&')
		(*t)->type = (c[i] == '>' ? 14 : 13);
	else if (c[i] == '>' && c[i + 1] == '>' && c[i + 2] == '&')
		(*t)->type = 18;
	else if (c[i] == c[i + 1] && (c[i] == '<' || c[i] == '>'))
		(*t)->type = (c[i] == '>' ? 11 : 10);
	else if (c[i] == '<' || c[i] == '>')
		(*t)->type = (c[i] == '>' ? 7 : 6);
	(*t)->content = (i == 0 ? ft_strdup("1") : ft_strndup(c, i));
}

int		check_token3(t_token **t, char *str, int s, int i)
{
	char	*c;

	c = ft_strndup(str, s);
	while (ft_isdigit(str[i]))
		i++;
	if (c[i] == '>' || c[i] == '<')
	{
		set_tok(c, t, i);
		ft_strdel(&c);
		return (1);
	}
	else if (c[0] == '&' && c[1] != '&')
	{
		set_tok1(c, t);
		ft_strdel(&c);
		return (1);
	}
	ft_strdel(&c);
	return (0);
}
