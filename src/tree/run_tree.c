/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 08:58:11 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 11:44:06 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		child_pid(int pipe1, int pipe0, t_tree *root)
{
	dup2(pipe1, STDOUT);
	close(pipe0);
	return (run_tree(root->left, 0));
}

int		exeec_pipe(t_tree *root)
{
	int		pipes[2];
	pid_t	pid[2];
	int		ret[2];

	if (pipe(pipes) < 0)
		return (0);
	if ((pid[0] = fork()) == 0)
	{
		ret[0] = child_pid(pipes[1], pipes[0], root);
		exit(0);
	}
	if ((pid[1] = fork()) == 0)
	{
		dup2(pipes[0], STDINN);
		close(pipes[1]);
		ret[1] = run_tree(root->right, 0);
		exit(0);
	}
	close(pipes[0]);
	close(pipes[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
	if (!ret[0] || !ret[1])
		return (0);
	return (1);
}

void	reset_fd(void)
{
	dup2(g_sel.fd[0], 0);
	dup2(g_sel.fd[1], 1);
	dup2(g_sel.fd[2], 2);
}

int		run_tree(t_tree *root, int ret)
{
	if (root && root->token == 4)
		ret = exeec_pipe(root);
	else if (root && root->token == 1)
	{
		ret = exeec_cmd(root, NULL);
		reset_fd();
	}
	else if (root && root->token == 3)
	{
		ret = run_tree(root->left, 0);
		ret = run_tree(root->right, 0);
	}
	else if (root && root->token == 8)
	{
		if ((ret = run_tree(root->left, 0)))
			ret = run_tree(root->right, 0);
	}
	else if (root && root->token == 9)
	{
		if (!(ret = run_tree(root->left, 0)))
			ret = run_tree(root->right, 0);
	}
	else if (root && ft_isredir(root->token))
		ret = exeec_redir(root);
	return (ret);
}
