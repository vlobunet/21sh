/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:59:59 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 11:18:43 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		ft_run_cmd(char **cmd)
{
	int ret;

	!ft_strcmp(cmd[0], "exit") ? run_exit() : 0;
	!ft_strcmp(cmd[0], "echo") ? ret = run_echo(cmd + 1, NULL, 0, 0) : 0;
	!ft_strcmp(cmd[0], "cd") ? ret = run_cd(cmd + 1) : 0;
	!ft_strcmp(cmd[0], "env") ? ret = run_env() : 0;
	!ft_strcmp(cmd[0], "setenv") ? ret = run_setenv(cmd + 1) : 0;
	!ft_strcmp(cmd[0], "help") ? ret = print_help_file(80, cmd[1], 0, 0) : 0;
	!ft_strcmp(cmd[0], "myman") ? ret = print_help_file(80, cmd[1], 1, 0) : 0;
	!ft_strcmp(cmd[0], "unsetenv") ? ret = run_unsetenv(cmd + 1) : 0;
	!ft_strcmp(cmd[0], "clear") ? ft_putstr("\033[0d\033[2J") : 0;
	!ft_strcmp(cmd[0], "as") ? ret = 0 : 0;
	!ft_strcmp(cmd[0], "21sh") ? ret = 0 : 0;
	return (ret);
}

int		command_check(char **cmd)
{
	int ret;

	if ((!ft_strcmp(cmd[0], "setenv")) ||
		(!ft_strcmp(cmd[0], "unsetenv")) ||
		(!ft_strcmp(cmd[0], "env")) ||
		(!ft_strcmp(cmd[0], "cd")) ||
		(!ft_strcmp(cmd[0], "echo")) ||
		(!ft_strcmp(cmd[0], "clear")) ||
		(!ft_strcmp(cmd[0], "help")) ||
		(!ft_strcmp(cmd[0], "myman")) ||
		(!ft_strcmp(cmd[0], "as")) ||
		(!ft_strcmp(cmd[0], "exit")) ||
		(!ft_strcmp(cmd[0], "21sh")))
		ret = ft_run_cmd(cmd);
	else
		return (-1);
	return (ret == 1 ? 0 : 1);
}
