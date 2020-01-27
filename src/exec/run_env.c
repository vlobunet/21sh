/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:33:58 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/16 13:02:36 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

char	*get_env(char *env, char **env_g)
{
	int		i;
	char	*env_join;
	int		size;

	i = -1;
	env_join = ft_strjoin(env, "=");
	size = ft_strlen(env_join);
	while (env_g[++i])
		if (ft_strncmp(env_g[i], env_join, size) == 0)
		{
			ft_strdel(&env_join);
			return (env_g[i] + size);
		}
	ft_putstr_fd("getenv: Wrong atribut: ", 2);
	ft_putendl_fd(env, 1);
	ft_strdel(&env_join);
	return (NULL);
}

int		run_env(void)
{
	int i;

	i = 0;
	while (g_sel.m_env[i])
		ft_putendl_fd(g_sel.m_env[i++], 1);
	return (1);
}

char	*run_get_env(char *env, char **env_g, int flag)
{
	int		i;
	char	*env_join;
	int		size;

	i = -1;
	env_join = ft_strjoin(env, "=");
	size = ft_strlen(env_join);
	while (env_g && env_g[++i])
		if (ft_strncmp(env_g[i], env_join, size) == 0)
		{
			ft_strdel(&env_join);
			return (env_g[i]);
		}
	flag ? ft_putstr_fd("Oops! ", 2) : 0;
	flag ? ft_putstr_fd(env, 2) : 0;
	flag ? ft_putendl_fd(": Not found!", 2) : 0;
	ft_strdel(&env_join);
	return (NULL);
}
