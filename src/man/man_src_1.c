/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_src_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 22:23:40 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/09 22:23:42 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int	man_clear(void)
{
	ft_putstr_fd("\n\033[01;38;05;226mNAME\033[m\n", 1);
	ft_putstr_fd("     \033[38;05;226mclear\033[m -- clear the terminal s", 1);
	ft_putstr_fd("creen\n\n\033[01;38;05;226mSYNOPSIS\033[m\n     ", 1);
	ft_putstr_fd("\033[38;05;226mclear\033[m\n\n\033[01;38;05;226mDESCRIP", 1);
	ft_putstr_fd("TION\033[m\n     \033[38;05;226mclear\033[m  clears you", 1);
	ft_putstr_fd("r screen if this is possible.  It looks in the\n     en", 1);
	ft_putstr_fd("vironment for the terminal type and then in the terminf", 1);
	ft_putstr_fd("o\n     database to figure out how to \033[38;05;226mcl", 1);
	ft_putstr_fd("ear\033[m the screen\n\n", 1);
	return (1);
}

int	man_man(void)
{
	ft_putstr_fd("\n\033[01;38;05;226mNAME\033[m\n", 1);
	ft_putstr_fd("     \033[38;05;226mmyman\033[m -- format and display t", 1);
	ft_putstr_fd("he on-line manual pages\n\n\033[01;38;05;226mSYNOPSIS", 1);
	ft_putstr_fd("\033[m\n     \033[38;05;226mmyman\033[m name_command\n", 1);
	ft_putstr_fd("\n", 1);
	return (1);
}

int	man_help(void)
{
	ft_putstr_fd("\n\033[01;38;05;226mNAME\033[m\n", 1);
	ft_putstr_fd("     \033[38;05;226mhelp\033[m -- format and display th", 1);
	ft_putstr_fd("e on-line manual pages\n\n\033[01;38;05;226mSYNOPSIS", 1);
	ft_putstr_fd("\033[m\n     \033[38;05;226mhelp\033[m\n\n", 1);
	return (1);
}

int	man_exit(void)
{
	ft_putstr_fd("\n\033[01;38;05;226mNAME\033[m\n", 1);
	ft_putstr_fd("     \033[38;05;226mexit\033[m -- format and display th", 1);
	ft_putstr_fd("e on-line manual pages\n\n\033[01;38;05;226mSYNOPSIS", 1);
	ft_putstr_fd("\033[m\n     \033[38;05;226mexit\033[m\n\n", 1);
	return (1);
}

int	run_man(char *str)
{
	int ret;

	ret = 0;
	if (!str)
	{
		ft_putstr_fd("What?\n", 2);
		return (0);
	}
	(!ft_strcmp(str, "echo")) ? ret = man_echo() : 0;
	(!ft_strcmp(str, "cd")) ? ret = man_cd() : 0;
	(!ft_strcmp(str, "env")) ? ret = man_env() : 0;
	(!ft_strcmp(str, "unsetenv")) ? ret = man_unsetenv() : 0;
	(!ft_strcmp(str, "setenv")) ? ret = man_setenv() : 0;
	(!ft_strcmp(str, "clear")) ? ret = man_clear() : 0;
	(!ft_strcmp(str, "man")) ? ret = man_man() : 0;
	(!ft_strcmp(str, "help")) ? ret = man_help() : 0;
	(!ft_strcmp(str, "exit")) ? ret = man_exit() : 0;
	if (ret == 0)
	{
		ft_putstr_fd("No manual entry for: ", 2);
		ft_putendl_fd(str, 2);
		return (0);
	}
	return (1);
}
