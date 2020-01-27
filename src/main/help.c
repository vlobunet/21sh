/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 22:23:22 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/09 22:23:27 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

struct termios	get_default_settings_help(void)
{
	char			buf[1024];
	struct termios	savetty;
	struct termios	tty;
	char			*name_t;

	((name_t = getenv("TERM")) == NULL) ? print_error_name_t() : 0;
	!isatty(0) ? print_error_term() : 0;
	((tgetent(buf, name_t)) == -1) ? print_error_data(-1) : 0;
	((tgetent(buf, name_t)) == 0) ? print_error_data(0) : 0;
	tcgetattr(0, &tty);
	savetty = tty;
	tty.c_lflag &= ~(ICANON | ECHO | ISIG);
	tty.c_cc[VMIN] = 1;
	tty.c_cc[VDSUSP] = _POSIX_VDISABLE;
	tty.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &tty);
	tputs(tgetstr("ti", NULL), 1, printnbr);
	tputs(tgetstr("vi", NULL), 1, printnbr);
	return (savetty);
}

void			res_default_settings_help(struct termios savetty)
{
	tcsetattr(0, TCSANOW, &savetty);
	tputs(tgetstr("ve", NULL), 1, printnbr);
	tputs(tgetstr("te", NULL), 1, printnbr);
}

void			exit_help(void)
{
	long		key;

	ft_putstr_fd("\033[7m", 1);
	ft_putstr_fd("\nPRESS Q or ESC TO EXIT PLEASE!", 1);
	ft_putstr_fd("\033[0m", 1);
	while (42)
	{
		key = 0;
		read(0, &key, 8);
		if (key == 113 || key == ESC)
			break ;
	}
}

int				print_help_file(int size, char *str, int flag, int ret)
{
	struct termios	savetty;
	struct winsize	s;

	savetty = get_default_settings_help();
	if (ioctl(0, TIOCGWINSZ, (char *)&s) < 0)
	{
		res_default_settings_help(savetty);
		ret = 0;
	}
	else if (s.ws_col <= size)
	{
		res_default_settings_help(savetty);
		ret = 1;
	}
	else
	{
		flag == 1 ? run_man(str) : run_help();
		exit_help();
		res_default_settings_help(savetty);
		ret = 2;
	}
	ret == 0 ? ft_putstr_fd("ERROR!\n", 1) : 0;
	ret == 1 ? ft_putstr_fd("RESIZE WINDOW PLEASE\n", 1) : 0;
	return (ret == 0 ? ret : 1);
}
