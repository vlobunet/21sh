/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_src.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:17:04 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 19:17:09 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	push_ret_cmd(char *cmd)
{
	char	*tmp;
	char	*src;
	t_token	*tok;

	tok = NULL;
	tmp = ft_strndup(cmd + 1, (int)ft_strlen(cmd + 1) - 1);
	src = ft_strjoin(tmp, " >> /tmp/log");
	ft_strdel(&tmp);
	if (token_main(src, &tok) > 0)
		run_token_cmd(tok);
	clear_token_lst(&tok);
}

char	*creat_file(char **cmd, int i, int fd, int coll)
{
	char	buf[1000];

	while (cmd[++i])
		if (cmd[i][0] == '`')
			push_ret_cmd(cmd[i]);
	fd = open("/tmp/log", O_RDONLY);
	if ((coll = read(fd, buf, 1000)) >= 0)
	{
		buf[coll] = '\0';
		while (coll-- > 0)
			if (buf[coll] == '\n')
				buf[coll] = ' ';
		close(fd);
		return (ft_strdup(buf));
	}
	close(fd);
	return (ft_strdup(" "));
}

char	**realoc_cmd(char **cmd, char **tmp, int i, char **ret)
{
	int	coll;

	coll = 0;
	while (cmd[++i])
		if (cmd[i][0] != 0)
			coll++;
	i = -1;
	while (tmp && tmp[++i])
		coll++;
	ret = (char **)malloc(sizeof(char *) * (coll + 1));
	i = -1;
	coll = 0;
	while (cmd[++i])
		if (cmd[i][0] != 0)
			ret[coll++] = ft_strdup(cmd[i]);
	i = -1;
	while (tmp && tmp[++i])
		ret[coll++] = ft_strdup(tmp[i]);
	ret[coll] = 0;
	ft_freestrarr(tmp);
	return (ret);
}

char	**set_cmds(char **cmd, char *tmp, char *buf)
{
	int		i;
	int		fd;
	char	**t;
	int		coll;

	i = -1;
	coll = 0;
	fd = open("/tmp/log", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	close(fd);
	buf = creat_file(cmd, -1, 0, 0);
	while (cmd[++i])
		if (cmd[i][0] == '`')
		{
			free(cmd[i]);
			cmd[i] = ft_strdup("");
		}
		else
			coll++;
	t = realoc_cmd(cmd, ft_strsplit(buf, 32), -1, NULL);
	ft_strdel(&buf);
	ft_strdel(&tmp);
	return (t);
}
