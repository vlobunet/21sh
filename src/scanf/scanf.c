/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:16:45 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/16 16:55:46 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

char		*line_editing(char *cmd, long key, int size_mess)
{
	key == LEFT ? go_left(1, size_mess) : 0;
	key == RIGHT ? go_right(cmd, 1) : 0;
	key == UP ? cmd = go_up(cmd, size_mess) : 0;
	key == DOWN ? cmd = go_down(cmd, size_mess) : 0;
	if (key == 127)
		cmd = del_sumb(cmd, size_mess);
	else if (key >= 32 && key < 127)
		cmd = print_sumb(key, cmd, size_mess);
	return (cmd);
}

void		ft_scanf_part_one(long key, int size_mess)
{
	key == HOME ? go_to_start_str(size_mess) : 0;
	key == END ? go_to_end_str(g_sel.cmd) : 0;
	key == ESC ? g_sel.cmd = full_deletion(g_sel.cmd, size_mess) : 0;
	key == DEL ? g_sel.cmd = del_after_cursor(g_sel.cmd) : 0;
	key == ALT_RT ? go_to_next_word(g_sel.cmd) : 0;
	key == ALT_LT && g_sel.pos[0] > 0 ?
	go_to_prev_word(g_sel.cmd, size_mess) : 0;
	key == 23 && g_sel.pos[2] > 0 ?
	g_sel.cmd = del_previous_word(g_sel.cmd, size_mess) : 0;
}

t_select	*init_sel(void)
{
	t_select	*new;

	new = (t_select *)malloc(sizeof(t_select));
	new->cmd = NULL;
	new->s = 0;
	new->os = 0;
	return (new);
}

void		ft_scanf_part_two(long key, int size_mess)
{
	t_select	*a;

	key == TAB && g_sel.cmd ? autocomplete(TAB, size_mess, 0, NULL) : 0;
	((key >= 32 && key <= 127) || key == LEFT || key == RIGHT ||
		key == UP || key == DOWN) ?
	g_sel.cmd = line_editing(g_sel.cmd, key, size_mess) : 0;
	key == S_L || key == S_R || key == S_H || key == S_E || key == SA_R ||
	key == SA_L || key == A_A ?
		select_start(key, size_mess, a = init_sel()) : 0;
	key == A_PST && g_sel.cpy ? paste_select(size_mess, NULL, NULL, NULL) : 0;
}

char		*ft_scanf(int fd, int size_mess)
{
	long		key;

	key = 0;
	g_sel.pos[2] = 0;
	g_sel.f = 0;
	while (key != 10 && !g_sel.f)
	{
		key = 0;
		read(fd, &key, 8);
		(key == 4 && (!g_sel.cmd || !*g_sel.cmd)) ? run_exit() : 0;
		(key == ESC && (!g_sel.cmd || !*g_sel.cmd)) ? run_exit() : 0;
		ft_scanf_part_one(key, size_mess);
		ft_scanf_part_two(key, size_mess);
		g_sel.f ? ft_strdel(&g_sel.cmd) : 0;
	}
	g_sel.pos[0] = size_mess;
	g_sel.f = 0;
	if_dquote_cmd();
	g_sel.cmd ? add_comand_to_story(g_sel.cmd) : 0;
	res_default_settings(g_sel.savetty);
	ft_putchar_fd('\n', 1);
	return (g_sel.cmd);
}
