/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:34:47 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/16 14:31:46 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		run_unset(char *cmd_attr, int i)
{
	int		size;
	char	*str;

	str = ft_strjoin(cmd_attr, "=");
	size = ft_strlen(str);
	while (g_sel.m_env[++i])
	{
		if (!ft_strncmp(str, g_sel.m_env[i], size))
		{
			ft_strdel(&g_sel.m_env[i]);
			while (g_sel.m_env[i + 1])
			{
				g_sel.m_env[i] = ft_strdup(g_sel.m_env[i + 1]);
				ft_strdel(&g_sel.m_env[i + 1]);
				i++;
			}
			g_sel.m_env = realloc_envv(i);
			ft_strdel(&str);
			return (0);
		}
	}
	ft_strdel(&str);
	return (error_unset(cmd_attr));
}

int		run_unsetenv(char **str)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	if (*str)
	{
		while (str[++i])
			ret = ret + (ft_strcmp(str[i], "HOME") ?
				run_unset(str[i], -1) : error_unset(str[i]));
		return (ret ? 0 : 1);
	}
	else
		return (error_unset(NULL));
}
