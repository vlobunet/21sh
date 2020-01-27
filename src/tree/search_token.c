/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 08:57:54 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/14 09:55:49 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

static t_lib	g_lib_op[LENLIB] =
{
	{.token = 3, .priority = 11},
	{.token = 9, .priority = 10},
	{.token = 8, .priority = 10},
	{.token = 4, .priority = 8},
	{.token = 6, .priority = 7},
	{.token = 7, .priority = 7},
	{.token = 10, .priority = 7},
	{.token = 11, .priority = 7},
	{.token = 12, .priority = 7},
	{.token = 13, .priority = 7},
	{.token = 14, .priority = 7},
	{.token = 18, .priority = 7},
	{.token = 19, .priority = 7},
	{.token = 20, .priority = 7},
	{.token = 21, .priority = 7},
	{.token = 22, .priority = 7},
};

static t_lib	*check_lib(t_token *node)
{
	int i;

	i = 0;
	while (i < LENLIB)
	{
		if (node->type == g_lib_op[i].token)
			return (&g_lib_op[i]);
		++i;
	}
	return (NULL);
}

int				compare_token_op(t_token *node_lst, t_token *tmp)
{
	t_lib	*lib_lst;
	t_lib	*lib_tmp;

	lib_lst = NULL;
	lib_tmp = NULL;
	lib_lst = check_lib(node_lst);
	lib_tmp = check_lib(tmp);
	if (!lib_lst && lib_tmp)
		return (1);
	else if (lib_lst && lib_tmp)
	{
		if (lib_lst->priority == lib_tmp->priority && lib_lst->priority > 10)
			return (0);
		if (lib_lst->priority <= lib_tmp->priority)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int				priority(t_token *node_lst, t_token *tmp)
{
	if (!node_lst && tmp->sel == 0)
		return (1);
	else if (compare_token_op(node_lst, tmp))
		return (1);
	else if (!node_lst && tmp->type == 1)
		return (1);
	return (0);
}

t_token			*search_toke(t_token *lst)
{
	t_token	*tmp;
	t_token	*node;

	tmp = lst;
	node = NULL;
	if (lst == NULL)
		return (NULL);
	if (tmp->sel == 1)
		tmp = tmp->next;
	while (tmp && tmp->sel == 0)
	{
		if (priority(node, tmp))
			node = tmp;
		tmp = tmp->next;
	}
	return (node);
}
