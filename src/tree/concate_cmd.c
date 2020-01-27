/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concate_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 08:57:07 by vlobunet          #+#    #+#             */
/*   Updated: 2018/07/29 08:57:09 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

t_token	*search_toke_prev(t_token *lst)
{
	t_token	*tmp;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	if (tmp->sel == 1)
		tmp = tmp->prev;
	while (tmp && tmp->prev && tmp->sel == 0)
		tmp = tmp->prev;
	return (search_toke(tmp));
}

t_tree	*recurs_creat_tree(t_token *lst)
{
	t_token	*tmp;
	t_tree	*node;

	tmp = lst;
	node = NULL;
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
	return (node);
}

void	cmd_len(t_token *lst, int *i, int *j)
{
	t_token	*tmp;
	int		tmpi;

	tmp = lst;
	tmpi = 0;
	while (tmp && (tmp->type == 1 || tmp->type == 17))
	{
		if ((tmpi = ft_strlen(tmp->content)) >= *j)
			*j = tmpi;
		*i = *i + 1;
		tmp = tmp->next;
	}
}

char	**concate_cmd(t_token *lst)
{
	t_token	*tmp;
	int		i;
	int		j;
	int		count;
	char	**argv;

	tmp = lst;
	count = 0;
	i = 0;
	j = 0;
	cmd_len(tmp, &i, &j);
	argv = NULL;
	if (!(argv = (char **)malloc(sizeof(char*) * (i * j + 1))))
		return (NULL);
	argv[i * j] = NULL;
	while (tmp && tmp->content && (count <= i - 1))
	{
		argv[count] = ft_strdup(tmp->content);
		++count;
		tmp->sel = 1;
		tmp = tmp->next;
	}
	argv[count] = NULL;
	return (argv);
}
