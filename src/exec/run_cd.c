/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:34:35 by vlobunet          #+#    #+#             */
/*   Updated: 2018/07/29 10:34:38 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

char	*ft_get_env_var(char *str)
{
	int	i;
	int	size;

	i = 0;
	if (!g_sel.m_env)
		return (NULL);
	size = ft_strlen(str);
	while (g_sel.m_env[i])
	{
		if (ft_strncmp(str, g_sel.m_env[i], size) == 0)
			return (g_sel.m_env[i] + size);
		i++;
	}
	return (NULL);
}

int		change_dir(char *path)
{
	char	*cwd;
	char	buff[4097];
	int		ret;

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
		ret = run_set("OLDPWD", cwd);
	else
	{
		ft_putstr_fd("cd: ", 2);
		if (access(path, F_OK) == -1)
			ft_putstr_fd("no such file or directory: ", 2);
		else if (access(path, R_OK) == -1)
			ft_putstr_fd("permission denied: ", 2);
		else
			ft_putstr_fd("not a directory: ", 2);
		ft_putendl_fd(path, 2);
		ret = 0;
	}
	return (ret);
}

int		run_cd(char **cmd)
{
	char	*home;
	char	*tmp;
	int		ret;

	ret = 1;
	home = ft_get_env_var("HOME=");
	if (!cmd || !*cmd || !**cmd)
		ret = change_dir(home);
	else if (cmd[0] && !cmd[1])
	{
		tmp = ft_strjoin(home, cmd[0] + 1);
		if (ft_strequ(cmd[0], "--"))
			ret = (change_dir(home));
		else if (ft_strequ(cmd[0], "-"))
			ret = (change_dir(ft_get_env_var("OLDPWD=")));
		else if (ft_strequ(cmd[0], "~"))
			ret = (change_dir(home));
		else if (cmd[0][0] == '~')
			ret = change_dir(tmp);
		else
			ret = (change_dir(cmd[0]));
		tmp ? ft_strdel(&tmp) : 0;
	}
	return (ret);
}
