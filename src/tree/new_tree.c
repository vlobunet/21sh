/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 08:56:15 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/13 19:30:38 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

t_tree	*add_tree(t_token *lst)
{
	t_tree	*node;

	node = ft_memalloc(sizeof(t_tree));
	node->token_or = lst;
	node->cmd = NULL;
	node->father = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

char	**copy_fd(t_token *tmp)
{
	char	**cmd;

	if (!(cmd = ft_memalloc(sizeof(char *) * 2)))
		return (NULL);
	if (tmp && tmp->content)
	{
		cmd[0] = ft_strdup(tmp->content);
		cmd[1] = NULL;
		return (cmd);
	}
	else
	{
		free(cmd);
		return (NULL);
	}
}

t_tree	*creat_left(t_token *lst)
{
	t_token	*tmp;

	tmp = NULL;
	if (!(tmp = search_toke_prev(lst)))
		return (NULL);
	tmp->sel = 1;
	return (recurs_creat_tree(tmp));
}

t_tree	*creat_right(t_token *lst)
{
	t_token	*tmp;

	tmp = NULL;
	if (!(tmp = search_toke(lst)))
		return (NULL);
	tmp->sel = 1;
	return (recurs_creat_tree(tmp));
}

t_tree	*new_tree(t_token *tok)
{
	t_tree	*node;
	t_token	*tmp;

	node = NULL;
	tmp = NULL;
	if (tok)
	{
		tmp = search_toke(tok);
		tmp->sel = 1;
		node = add_tree(tmp);
		node->token = tmp->type;
		if (tmp->type == 1)
			node->cmd = concate_cmd(tmp);
		if (ft_is_dir(tmp->type))
			node->cmd = copy_fd(tmp);
		if (tmp->type == 16)
			node->cmd = copy_fd(tmp);
		node->right = creat_right(tmp);
		if (node->right)
			node->right->father = node;
		node->left = creat_left(tmp);
		if (node->left)
			node->left->father = node;
	}
	return (node);
}
