/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 08:51:17 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/16 16:55:34 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

static void	suspend(void)
{
	res_default_settings(g_sel.savetty);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void		exit_signal(void)
{
	res_default_settings(g_sel.savetty);
	exit(EXIT_SUCCESS);
}

void		sigint_signal(void)
{
	res_default_settings(g_sel.savetty);
	g_sel.f ? ft_putchar_fd('\n', 0) : 0;
	g_sel.f ? ft_print_message() : 0;
	g_sel.f = 1;
	g_sel.pos[0] = g_sel.strlen_mes;
	g_sel.pos[1] = 0;
	g_sel.pos[2] = 0;
	init_shell();
}

void		sigwinch_signal(void)
{
	g_sel.cmd = full_deletion(g_sel.cmd, g_sel.strlen_mes);
}

void		get_sigint(int sig)
{
	int status;
	int pid;

	pid = waitpid(-1, &status, WUNTRACED);
	if (sig == SIGTSTP)
		suspend();
	else if (sig == SIGINT)
		sigint_signal();
	else if (sig == SIGWINCH)
		sigwinch_signal();
	else if (sig == SIGCONT)
	{
		ft_print_message();
		init_shell();
		g_sel.pos[0] = g_sel.strlen_mes;
		g_sel.pos[1] = 0;
		g_sel.pos[2] = 0;
		ft_printf(0, g_sel.cmd, g_sel.strlen_mes);
	}
	else
		exit_signal();
}
