/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 08:46:03 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 19:30:51 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		count_char(char *s)
{
	int len;
	int ln;

	ln = ft_strlen(s);
	len = 0;
	while (ln - len >= 0 && s[ln - len] == '\\')
		len += 1;
	return (len);
}

int		is_new_prompt(t_token *prev)
{
	if (prev)
	{
		if (!(prev = prev->next))
			return (1);
		if (ft_is_dir(prev->type))
			return (ft_err_message("newline"));
		if ((ft_is_separ(prev->type) && prev->type != 3) ||
			(count_char(prev->content) % 2 == 1))
			return (-3);
	}
	return (1);
}

int		ft_is_error(t_token *tmp, t_token *prev)
{
	if (tmp && tmp->type == 3 && (!prev || prev->type == 3))
		return (0);
	if (tmp && (tmp->type != 1 && !prev))
		return (ft_err_message("No commando before '`'"));
	if (tmp && (tmp->type == 1 && !tmp->content[0]))
		return (ft_err_message("Command not found"));
	if (tmp && !ft_is_dir(tmp->type) && !ft_strcmp(tmp->content, "&"))
		return (ft_err_message(tmp->content));
	if (ft_is_separ(tmp->type) && (!prev || ft_is_separ(prev->type) ||
		ft_is_dir(prev->type)))
		return (ft_err_message(tmp->content));
	if (ft_is_dir(tmp->type) && (prev && ft_is_dir(prev->type)))
		return (ft_err_message(tmp->content));
	return (0);
}

void	set_token_str(t_token *tmp)
{
	char	*new_tmp;
	int		i[3];

	new_tmp = NULL;
	if (tmp && tmp->type == 17 && (tmp->content[0] == '\"' ||
		tmp->content[0] == '\''))
	{
		new_tmp = ft_strndup(tmp->content + 1, ft_strlen(tmp->content) - 2);
		ft_strdel(&tmp->content);
		tmp->content = ft_strdup(new_tmp);
		ft_strdel(&new_tmp);
	}
	else if (tmp && tmp->type == 17 && (tmp->content[0] == '`'))
		divide_the_string(tmp, NULL, NULL, i);
}

int		validity_test(t_token **lst)
{
	t_token	*tmp;
	t_token	*prev;
	int		ret;

	if (!*lst)
		return (0);
	tmp = *lst;
	prev = NULL;
	while (tmp)
	{
		prev = tmp->prev;
		if ((ret = ft_is_error(tmp, prev)))
			return (ret);
		set_token_str(tmp);
		tmp = tmp->next;
	}
	if (!prev && (count_char((*lst)->content) % 2 == 1))
		return (-3);
	return (is_new_prompt(prev));
}
