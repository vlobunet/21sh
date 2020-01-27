/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeec_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 08:53:28 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 11:37:17 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		open_file(t_tree *tr)
{
	if (tr->token == 7 || tr->token == 19)
		return (open(tr->right->cmd[0], O_WRONLY | O_CREAT | O_TRUNC, 0600));
	if (tr->token == 11 || tr->token == 21)
		return (open(tr->right->cmd[0], O_WRONLY | O_APPEND | O_CREAT, 0600));
	if (tr->token == 6)
		return (open(tr->right->cmd[0], O_RDONLY | O_CREAT, 0600));
	return (-1);
}

int		ft_isredir(int type)
{
	if (type == 6 || type == 7 || type == 11 || type == 13 || type == 14 ||
		type == 18 || type == 19 || type == 20 || type == 21 || type == 22)
		return (1);
	return (0);
}

int		exeec_redir(t_tree *n)
{
	int fd;

	if ((fd = open_file(n)) == -1)
		fd = (n->right->cmd[0][0] != '-' ? ft_atoi(n->right->cmd[0]) : -1);
	if (fd == -1 && (n->token == 14 || n->token == 18))
		close(ft_atoi(n->cmd[0]));
	else if (fd > 0 && (n->token == 19 || n->token == 21))
	{
		dup2(fd, 0);
		dup2(fd, 1);
		dup2(fd, 2);
	}
	else if (fd > 0 && (n->token == 7 || n->token == 11 || n->token == 14))
		dup2(fd, ft_atoi(n->cmd[0]));
	return (run_tree(n->left, 0));
}
