/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:59:24 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 13:10:14 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	free_func(char *str, t_scanf *q)
{
	if (str)
	{
		ft_strdel(&str);
		str = NULL;
	}
	if (q)
	{
		if (q->cmd)
			ft_strdel(&q->cmd);
		free(q);
		q = NULL;
	}
}

int		checcmd(char *cmd)
{
	int		qt;
	char	q;
	int		i;

	q = 0;
	qt = 0;
	i = -1;
	while (cmd[++i])
	{
		if ((cmd[i] == '"' || cmd[i] == '\'' || cmd[i] == '`') && !q)
			q = cmd[i];
	}
	i = -1;
	while (cmd[++i])
		if (cmd[i] == q)
			qt++;
	return (qt % 2 == 0 ? 1 : 0);
}

t_scanf	*new_scanf(int fd, int size_mess)
{
	t_scanf *q;

	q = (t_scanf *)malloc(sizeof(t_scanf));
	q->cmd = NULL;
	q->key = 0;
	g_sel.pos[0] = size_mess;
	g_sel.pos[2] = 0;
	while (q->key != 10)
	{
		q->key = 0;
		if (g_sel.f)
			break ;
		read(fd, &q->key, 8);
		if ((q->key == 4 && !q->cmd) || g_sel.f || q->key == 10)
			break ;
		q->key == HOME ? go_to_start_str(size_mess) : 0;
		q->key == END ? go_to_end_str(q->cmd) : 0;
		q->key == ESC ? q->cmd = full_deletion(q->cmd, size_mess) : 0;
		((q->key >= 32 && q->key <= 127) || q->key == LEFT || q->key == RIGHT) ?
		q->cmd = line_editing(q->cmd, q->key, size_mess) : 0;
	}
	g_sel.pos[0] = size_mess;
	return (q);
}

void	if_dquote_cmd(void)
{
	char	*str;
	t_scanf *q;

	if (!g_sel.cmd || !*g_sel.cmd)
		return ;
	while (g_sel.cmd && !checcmd(g_sel.cmd) && !g_sel.f)
	{
		str = ft_strjoin(g_sel.cmd, "\n");
		ft_strdel(&g_sel.cmd);
		g_sel.cmd = ft_strdup(str);
		ft_strdel(&str);
		g_sel.pos[2]++;
		ft_putstr_fd("\nmyquote> ", 1);
		q = new_scanf(0, ft_strlen("myquote> "));
		if (q->cmd)
			str = (ft_strjoin(g_sel.cmd, q->cmd));
		else if (!q->cmd && q->key != 10)
			str = NULL;
		ft_strdel(&g_sel.cmd);
		g_sel.cmd = (str ? ft_strdup(str) : NULL);
		free_func(str, q);
	}
	((!g_sel.cmd || !checcmd(g_sel.cmd))) ? print_error_quote() : 0;
	return ;
}
