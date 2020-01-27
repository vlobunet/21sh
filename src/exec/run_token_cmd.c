/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_token_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:34:12 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 11:20:31 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void		ft_push_ast(t_token *tok, t_tree **ast, t_token *tt, t_token *t)
{
	t_tree	*head_node;

	tt = tok;
	while (tt)
	{
		if (tt->prev && tt->type == 0 && tt->prev->type == 16)
		{
			t = tt;
			tt->prev ? tt->prev->next = tt->next : 0;
			tt->next ? tt->next->prev = tt->prev : 0;
			while (tt && tt->type != 17 && tt->type != 1)
				tt = tt->prev;
			t->prev = tt;
			t->next = tt->next;
			tt->next ? tt->next->prev = t : 0;
			tt->next = t;
			t->type = 17;
			tt = t;
		}
		else
			tt = tt->next;
	}
	head_node = new_tree(tok);
	*ast = head_node;
}

void		destruction_tree(t_tree *root)
{
	if (root == NULL)
		return ;
	destruction_tree(root->left);
	destruction_tree(root->right);
	ft_freestrarr(root->cmd);
	free(root);
	root = NULL;
	return ;
}

int			run_token_cmd(t_token *tok)
{
	t_tree	*ast;
	t_token	*tmp;

	ast = NULL;
	if (!tok)
		return (0);
	tmp = tok;
	ft_push_ast(tmp, &ast, NULL, NULL);
	g_sel.fd[0] = dup(0);
	g_sel.fd[1] = dup(1);
	g_sel.fd[2] = dup(2);
	run_tree(ast, 0);
	destruction_tree(ast);
	return (0);
}
