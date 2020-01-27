/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:33:45 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/16 13:07:27 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

char	*set_echo_cmd(char **cmd)
{
	int		fd;
	char	*buf;

	fd = open("/tmp/log", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	close(fd);
	buf = creat_file(cmd, -1, 0, 0);
	return (buf);
}

int		run_echo(char **s, char *t, int flag, int i)
{
	if (*s && !ft_strcmp(*s, "-n"))
	{
		s++;
		flag = 1;
	}
	while (s[i])
	{
		if (s[i][0] == '`')
			t = set_echo_cmd(s);
		else
			t = ft_strdup(s[i]);
		i++;
		ft_putstr_fd(((t && t[0] == '=') ? t + 1 : t), 1);
		s[i] ? ft_putstr_fd(" ", 1) : 0;
		ft_strdel(&t);
	}
	if (flag)
		ft_putstr_fd("\033[7m%\033[0m", 1);
	ft_putchar_fd('\n', 1);
	return (1);
}
