/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 11:00:36 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/13 18:40:37 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

char	**ft_get_env(char **env)
{
	int		i;
	char	**menv;

	i = 1;
	if (!env)
		return (NULL);
	while (env[i])
		i++;
	menv = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
	{
		menv[i] = ft_strdup(env[i]);
	}
	return (menv);
}

void	ft_freestrarr(char **arr)
{
	int i;

	if (arr == NULL)
		return ;
	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

void	clear_story_lst(t_history **story)
{
	t_history	*head;

	if (!*story)
		return ;
	while ((*story)->next)
	{
		head = (*story)->next;
		ft_strdel(&(*story)->content);
		(*story)->next->prev = NULL;
		*story ? free(*story) : 0;
		*story = head;
	}
	(*story)->content ? ft_strdel(&(*story)->content) : 0;
	*story ? free(*story) : 0;
}

void	run_exit(void)
{
	res_default_settings(g_sel.savetty);
	exit(0);
}

int		main(int argc, char **argv, char **env)
{
	t_token	*tok;

	argc = 0;
	argv = NULL;
	tok = NULL;
	g_sel.m_env = ft_get_env(env);
	init_shell();
	init_signal();
	while (1)
	{
		ft_print_message();
		g_sel.cmd = NULL;
		if (token_main(ft_scanf(0, g_sel.strlen_mes), &tok) > 0)
			run_token_cmd(tok);
		clear_token_lst(&tok);
	}
	clear_story_lst(&g_sel.story);
	ft_freestrarr(g_sel.m_env);
	res_default_settings(g_sel.savetty);
	return (0);
}
