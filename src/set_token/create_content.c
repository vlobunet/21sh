/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:00:05 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/19 10:00:07 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

char	*realloc_str(char *str, int i, char *t, int size)
{
	char	*ret;
	int		p;

	t ? t++ : 0;
	p = -1;
	ret = ft_strnew((int)ft_strlen(str) - size + (int)ft_strlen(t));
	while (++p != i)
		ret[p] = str[p];
	while (t && *t)
		ret[p++] = *t++;
	i = i + size;
	while (str[i])
		ret[p++] = str[i++];
	ft_strdel(&str);
	str = ft_strdup(ret);
	ft_strdel(&ret);
	return (str);
}

char	*set_dollar(char *str, int i, int j, int size)
{
	char *t;
	char *word;

	while (str[++i])
		if (str[i] == '$' && *str != '\'')
		{
			j = i;
			while (str[j] && str[j] > 32 && str[j++] != '"')
				size++;
			word = ft_strndup(str + i, size);
			t = (run_get_env(word + 1, g_sel.m_env, 0) ?
			ft_strdup(ft_strchr(run_get_env(word + 1, g_sel.m_env, 0), '=')) :
			NULL);
			str = realloc_str(str, i, t, size);
			ft_strdel(&word);
			ft_strdel(&t);
			size = 0;
		}
	return (str);
}

char	*create_content(char *tmp, int i, int j)
{
	char	*str;

	str = ft_strnew((int)ft_strlen(tmp));
	while (tmp[i] && tmp[i + 1])
		if (tmp[i] != '\\')
			str[j++] = tmp[i++];
		else if (tmp[i] == '\\' && (tmp[i + 1] != 'n' || (*tmp != '"' &&
		*tmp != '\'')))
		{
			str[j++] = tmp[++i];
			i++;
		}
		else if (tmp[i] == '\\')
		{
			str[j++] = '\n';
			i = i + 2;
		}
	str[j] = tmp[i];
	ft_strdel(&tmp);
	tmp = set_dollar(str, -1, 0, 0);
	return (tmp);
}
