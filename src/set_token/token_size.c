/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:34:25 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 11:37:01 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		get_str_size(char *s, int flag)
{
	int i;

	i = 0;
	if (flag == 1)
		while (s[i] && (ft_isalpha(s[i]) || ft_isdigit(s[i]) ||
			s[i] == '-' || s[i] == '_' || s[i] == '/' || s[i] == '~' ||
			s[i] == '.' || s[i] == ':' || s[i] == '\\'))
			i = i + (s[i] == '\\' ? 2 : 1);
	else if (flag == 2)
	{
		while (s[i + 1] != s[0])
			i++;
		i = ((s[i + 1] && s[i + 1] == s[0]) ? i + 2 : 0);
	}
	else
		while (s[i] && (ft_isalpha(s[i]) || ft_isdigit(s[i]) || s[i] == '_' ||
			s[i] == '\\' || s[i] == '$'))
			i = i + (s[i] == '\\' ? 2 : 1);
	return (i);
}

int		get_token_size(char *s)
{
	int size;

	size = 0;
	*s == ';' ? size = 1 : 0;
	(*s == '|' || *s == '&') ? size = get_size(s, 0, 0) : 0;
	ft_isdigit(*s) ? size = get_size(s, 1, 0) : 0;
	(*s == '>' || *s == '<') ? size = get_redirected(s, 0) : 0;
	(ft_isalpha(*s) || *s == '/' || *s == '-' || *s == '~' || \
		*s == '.' || *s == '\\' || *s == '=') ? size = get_str_size(s, 1) : 0;
	*s == '$' ? size = get_str_size(s, 3) : 0;
	(*s == '"' || *s == '\'' || *s == '`') ?
		size = get_str_size(s, 2) : 0;
	*s == 32 ? size = 1 : 0;
	*s == '\n' ? size = 1 : 0;
	return (size);
}
