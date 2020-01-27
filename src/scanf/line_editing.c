/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:00:57 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/16 17:13:53 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	print_key(char key, int flag)
{
	struct winsize	s;

	tputs(tgetstr("cd", NULL), 1, printnbr);
	if (ioctl(0, TIOCGWINSZ, (char *)&s) < 0 || key == 0)
		return ;
	if (g_sel.pos[0] + 1 == s.ws_col || key == '\n')
	{
		while (g_sel.pos[0] != 0)
		{
			g_sel.pos[0]--;
			ft_putchar_fd('\b', 1);
		}
		tputs(tgetstr("do", NULL), 1, printnbr);
		g_sel.pos[1]++;
	}
	key != '\n' ? ft_putchar_fd(key, 1) : 0;
	key != '\n' ? g_sel.pos[0]++ : 0;
	flag == 1 ? g_sel.pos[2]++ : 0;
}

void	ft_printf(char key, char *str, int size_mess)
{
	struct winsize	s;
	int				i;

	i = 0;
	if (ioctl(0, TIOCGWINSZ, (char *)&s) < 0)
		return ;
	print_key(key, 1);
	if (str && *str)
	{
		while (str[i])
			print_key(str[i++], 1);
		while (i)
		{
			go_left(1, size_mess);
			i--;
		}
	}
}

char	*del_sumb(char *s1, int size_mess)
{
	char	*dup;
	char	*tmp;
	int		flag;

	flag = 0;
	if (g_sel.pos[2] == 0)
	{
		tputs(tgetstr("bl", NULL), 1, printnbr);
		return (s1);
	}
	dup = ft_strnew(g_sel.pos[2]);
	s1 ? dup = ft_strncpy(dup, s1, g_sel.pos[2] - 1) : 0;
	dup[g_sel.pos[2]] = 0;
	tmp = ((s1 && g_sel.pos[2] < (int)ft_strlen(s1)) ?\
	ft_strjoin(dup, s1 + g_sel.pos[2]) : ft_strdup(dup));
	go_left(1, size_mess);
	g_sel.pos[2] == 0 ? flag = 1 : 0;
	g_sel.pos[2] == 0 ? g_sel.pos[2]++ : 0;
	flag == 1 ? ft_printf(0, s1 + g_sel.pos[2], size_mess) :\
	ft_printf(0, s1 + g_sel.pos[2] + 1, size_mess);
	flag == 1 ? g_sel.pos[2]-- : 0;
	ft_strdel(&dup);
	ft_strdel(&s1);
	return (tmp);
}

char	*print_sumb(char buff, char *s1, int size_mess)
{
	char	*dup;
	char	*tmp;

	dup = ft_strnew(g_sel.pos[2] + 1);
	s1 ? dup = ft_strncpy(dup, s1, g_sel.pos[2]) : 0;
	dup[g_sel.pos[2]] = buff;
	tmp = ((s1 && g_sel.pos[2] < (int)ft_strlen(s1)) ?\
	ft_strjoin(dup, s1 + g_sel.pos[2]) : ft_strdup(dup));
	ft_printf(buff, s1 + g_sel.pos[2], size_mess);
	ft_strdel(&dup);
	ft_strdel(&s1);
	return (tmp);
}
