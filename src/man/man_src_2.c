/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_src_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 22:23:53 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/09 22:23:54 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int	man_echo(void)
{
	ft_putstr_fd("\033[01;38;05;226mNAME:\033[m\n     \033[38;05;226mecho", 1);
	ft_putstr_fd(" -- write arguments to the standard output\n\n", 1);
	ft_putstr_fd("\033[01;38;05;226mSYNOPSIS\033[m\n     \033[38;05;226me", 1);
	ft_putstr_fd("cho\033[m [\033[38;05;226m-n\033[m] [string ...]\n\n", 1);
	ft_putstr_fd("\033[01;38;05;226mDESCRIPTION\033[m\n", 1);
	ft_putstr_fd("     The \033[38;05;226mecho\033[m utility writes any s", 1);
	ft_putstr_fd("pecified operands, separated by single\n     blank (` '", 1);
	ft_putstr_fd(") characters and followed by a newline (`\\n') characte", 1);
	ft_putstr_fd("r,\n     to the standard output.\n\n     The following ", 1);
	ft_putstr_fd("option is available:\n\n     \033[38;05;226m-n\033[m   ", 1);
	ft_putstr_fd(" Do not print the trailing newline character\n\n", 1);
	return (1);
}

int	man_cd(void)
{
	ft_putstr_fd("\n\033[01;38;05;226mNAME\033[m\n     \033[38;05;226mcd", 1);
	ft_putstr_fd("\033[m -- change working directory\n\n", 1);
	ft_putstr_fd("\033[01;38;05;226mSYNOPSIS\033[m\n     \033[38;05;226mc", 1);
	ft_putstr_fd("d\033[m [directory]\n\n\033[01;38;05;226mDESCRIPTION", 1);
	ft_putstr_fd("\033[m\n     Directory is an absolute or relative pathn", 1);
	ft_putstr_fd("ame which becomes the new work-\n     ing directory.  T", 1);
	ft_putstr_fd("he interpretation of a relative pathname by ", 1);
	ft_putstr_fd("\033[38;05;226mcd\033[m depends\n     on the CDPATH env", 1);
	ft_putstr_fd("ironment variable.\n\n", 1);
	return (1);
}

int	man_env(void)
{
	ft_putstr_fd("\n\033[01;38;05;226mNAME\033[m\n", 1);
	ft_putstr_fd("     \033[38;05;226menv\033[m -- display environment\n", 1);
	ft_putstr_fd("\n\033[01;38;05;226mSYNOPSIS\033[m\n", 1);
	ft_putstr_fd("     \033[38;05;226menv\033[m [directory]\n\n", 1);
	return (1);
}

int	man_setenv(void)
{
	ft_putstr_fd("\n\033[01;38;05;226mNAME\033[m\n", 1);
	ft_putstr_fd("     \033[38;05;226msetenv\033[m -- set environment\n", 1);
	ft_putstr_fd("\n\033[01;38;05;226mSYNOPSIS\033[m\n", 1);
	ft_putstr_fd("     \033[38;05;226msetenv\033[m [name value]\n\n", 1);
	ft_putstr_fd("\033[01;38;05;226mDESCRIPTION\033[m\n", 1);
	ft_putstr_fd("     Modifies the environment variable. If the variable", 1);
	ft_putstr_fd(" does not exist then the\n     command will add a varia", 1);
	ft_putstr_fd("ble to the end of the list.\n\n", 1);
	return (1);
}

int	man_unsetenv(void)
{
	ft_putstr_fd("\n\033[01;38;05;226mNAME\033[m\n", 1);
	ft_putstr_fd("     \033[38;05;226munsetenv\033[m -- Removes the envir", 1);
	ft_putstr_fd("onment variable\n\n\033[01;38;05;226mSYNOPSIS\033[m\n  ", 1);
	ft_putstr_fd("   \033[38;05;226munsetenv\033[m [name..name..]\n\n", 1);
	ft_putstr_fd("\033[01;38;05;226mDESCRIPTION\033[m\n     Removes the e", 1);
	ft_putstr_fd("nvironment variable. If the variable does not exist the", 1);
	ft_putstr_fd("n the\n     command will issue a warning.\n", 1);
	ft_putstr_fd("\033[01;38;05;226mIMPORTANT:\033[m\n     You can not de", 1);
	ft_putstr_fd("lete the \033[38;05;226mHOME\033[m variable\n     To ma", 1);
	ft_putstr_fd("intain the terminal's operability, it is not recommende", 1);
	ft_putstr_fd("d to delete\n     the \033[38;05;226mPATH\033[m variabl", 1);
	ft_putstr_fd("e.\n\n", 1);
	return (1);
}
