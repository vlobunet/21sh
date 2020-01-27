/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 11:00:13 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 19:17:34 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		ft_run_fork(pid_t p, char *src, char **cmd, char **env)
{
	int ret;
	int re;

	ret = 1;
	re = 0;
	if (p == 0)
	{
		init_shell();
		signal_dfl();
		ret = execve(src, cmd, env);
	}
	else if (p > 0)
	{
		signal(SIGINT, SIG_IGN);
		waitpid(p, &re, WUNTRACED);
		if (WIFSTOPPED(re))
		{
			kill(p, SIGKILL);
			wait(&re);
		}
		init_shell();
	}
	return (p < 0 ? 0 : ret);
}

int		launch_cmd(char *path, char **cmd, char **env, int ret)
{
	char	*tmp;
	char	*src;
	char	**cmd1;

	tmp = ft_strjoin(path, "/");
	src = ft_strjoin(tmp, cmd[0]);
	ft_strdel(&tmp);
	if (access(src, 0 | 1) == 0)
	{
		cmd1 = set_cmds(cmd, NULL, NULL);
		ret = ft_run_fork(fork(), src, cmd1, env);
		ft_freestrarr(cmd1);
		cmd1 = NULL;
		ft_strdel(&tmp);
	}
	else
		ret = -1;
	ft_strdel(&src);
	return (ret);
}

char	*exeec_cmd_src(char *cmd, char *tmp1, char *tmp0)
{
	ft_strdel(&tmp1);
	ft_strdel(&cmd);
	cmd = ft_strdup(tmp0);
	ft_strdel(&tmp0);
	return (cmd);
}

int		exeec_cmd(t_tree *root, char **p)
{
	char	*tmp[2];
	int		i[2];

	i[0] = -1;
	i[1] = 0;
	if ((i[1] = command_check(root->cmd)) == 0)
		return (0);
	if (i[1] > 0)
		return (i[1]);
	if (ft_strchr(root->cmd[0], '/'))
	{
		tmp[0] = ft_strdup(ft_strrchr(root->cmd[0], '/') + 1);
		tmp[1] = ft_strndup(root->cmd[0], \
			ft_strlen(root->cmd[0]) - ft_strlen(tmp[0]) - 1);
		p = ft_strsplit(tmp[1], ':');
		root->cmd[0] = exeec_cmd_src(root->cmd[0], tmp[1], tmp[0]);
	}
	else
		p = ft_strsplit(ft_strchr(run_get_env("PATH", \
			g_sel.m_env, 1), '/'), ':');
	while (p && p[++i[0]] && i[1] == -1)
		(launch_cmd(p[i[0]], root->cmd, g_sel.m_env, 0) >= 0) ? i[1]++ : 0;
	i[1] == -1 ? print_error(root->cmd[0]) : 0;
	p ? ft_freestrarr(p) : 0;
	return (!i[1] ? 0 : 1);
}
