/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmessage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:35:39 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/12 15:56:16 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

char	*get_host_name(void)
{
	char	str[128];

	if (gethostname(str, sizeof(str)) != -1)
		return (ft_strndup(str,\
			(ft_strlen(str) - ft_strlen(ft_strchr(str, '.')))));
	else
		return (NULL);
}

char	*ft_goto(char *cwd, char *homedir)
{
	char	*pwd;

	if (ft_strcmp(cwd, homedir) == 0)
		pwd = ft_strdup(" ~");
	else if (!ft_strncmp(cwd, homedir, ft_strlen(homedir)))
	{
		while (*cwd++ == *homedir++)
			;
		pwd = ft_strjoin(" ~", --cwd);
	}
	else
		pwd = ft_strjoin(" ", cwd);
	return (pwd);
}

void	ft_print_message(void)
{
	char	buff[4097];
	char	*pwd;
	char	*str;

	g_sel.savetty = get_default_settings();
	g_sel.strlen_mes = 0;
	str = get_host_name();
	get_cursor_x() != 1 ? ft_putchar_fd('\n', 1) : 0;
	g_sel.strlen_mes = g_sel.strlen_mes + ft_strlen(str);
	ft_putstr_fd("\033[38;05;220m", 1);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
	str = getenv("HOME");
	ft_putstr_fd("\033[0m\033[38;05;21m", 1);
	pwd = ft_goto(getcwd(buff, 4096), str);
	g_sel.strlen_mes = g_sel.strlen_mes + ft_strlen(pwd);
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd(" $> ", 1);
	ft_putstr_fd("\033[0m", 1);
	g_sel.strlen_mes = g_sel.strlen_mes + 4;
	ft_strdel(&pwd);
	g_sel.pos[0] = g_sel.strlen_mes;
	g_sel.pos[1] = 0;
}
