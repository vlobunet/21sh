/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:35:08 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/12 15:53:39 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

char	**realloc_envv(int size)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	i = -1;
	while (g_sel.m_env[++i] && i < size)
	{
		new[i] = ft_strdup(g_sel.m_env[i]);
		ft_strdel(&g_sel.m_env[i]);
	}
	free(g_sel.m_env);
	g_sel.m_env = NULL;
	return (new);
}

int		run_set(char *cmd_attr0, char *cmd_attr1)
{
	int		i;
	int		size;
	char	*atribut;

	i = -1;
	atribut = ft_strjoin(cmd_attr0, "=");
	size = ft_strlen(atribut);
	while (g_sel.m_env[++i])
		if (!ft_strncmp(atribut, g_sel.m_env[i], size))
		{
			ft_strdel(&g_sel.m_env[i]);
			g_sel.m_env[i] = ft_strjoin(atribut, cmd_attr1);
			ft_strdel(&atribut);
			return (1);
		}
	g_sel.m_env = realloc_envv(i + 1);
	g_sel.m_env[i++] = ft_strjoin(atribut, cmd_attr1);
	ft_strdel(&atribut);
	g_sel.m_env[i] = 0;
	return (1);
}

int		run_setenv(char **atribut)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!atribut || !*atribut)
	{
		ft_putendl_fd("setenv : invalid number of attributes", 2);
		return (ret);
	}
	while (atribut[i])
		i++;
	if (i == 2)
		ret = run_set(atribut[0], atribut[1]);
	else
	{
		i > 2 ? ft_putendl_fd("setenv : Too many atribut.", 2) : 0;
		i < 2 ? ft_putendl_fd("setenv : Too few atribut.", 2) : 0;
		return (ret);
	}
	return (ret);
}
