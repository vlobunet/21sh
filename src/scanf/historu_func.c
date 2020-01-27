/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historu_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 10:22:27 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/16 15:41:07 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	add_comand_to_story(char *cmd)
{
	t_history *new;

	if (g_sel.story)
		while (g_sel.story->prev)
			g_sel.story = g_sel.story->prev;
	new = ft_lstnew_el(cmd, (g_sel.story ? g_sel.story->id + 1 : 1));
	if (g_sel.story)
	{
		g_sel.story->prev = new;
		new->next = g_sel.story;
	}
	g_sel.story = new;
	g_sel.real_story = g_sel.story->id;
	return ;
}

char	*history_up(char *cmd, int size_mess)
{
	int	i;

	i = 0;
	if (!g_sel.story)
		return (cmd);
	cmd = full_deletion(cmd, size_mess);
	cmd = ft_strdup(g_sel.story->content);
	if (cmd && *cmd)
		while (cmd[i])
			print_key(cmd[i++], 1);
	g_sel.real_story = g_sel.story->id;
	if (g_sel.story->next)
		g_sel.story = g_sel.story->next;
	return (cmd);
}

char	*history_down(char *cmd, int size_mess)
{
	int	i;

	i = 0;
	if (!g_sel.story)
		return (cmd);
	if (g_sel.story->prev)
	{
		g_sel.story->id != g_sel.real_story ?\
		g_sel.story = g_sel.story->prev : 0;
		g_sel.story->prev ? g_sel.story = g_sel.story->prev : 0;
		cmd = full_deletion(cmd, size_mess);
		cmd = ft_strdup(g_sel.story->content);
		if (cmd && *cmd)
			while (cmd[i])
				print_key(cmd[i++], 1);
		g_sel.real_story = g_sel.story->id;
	}
	else
		cmd = full_deletion(cmd, size_mess);
	return (cmd);
}
