/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocoplete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:46:42 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/16 15:15:05 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	free_all(t_tmp tmp, t_token *t)
{
	ft_strdel(&tmp.left);
	ft_strdel(&tmp.right);
	ft_lstdel_all(&tmp.e);
	ft_tokdel_all(&t);
}

int		chek_cmd(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == 32)
		i++;
	return (!str[i] ? 0 : 1);
}

void	token_src_1(char *str, t_token **lst)
{
	int	size_token;
	int	i;

	size_token = 1;
	i = 0;
	if (!str)
		return ;
	while (size_token > 0 && *(str + i))
	{
		size_token = get_token_size(str + i);
		*(str + i) != 32 ?
		add_token_lst(lst, creat_token(str + i, size_token, NULL)) : 0;
		i = i + size_token;
	}
	while (*lst && (*lst)->prev)
		*lst = (*lst)->prev;
	check_token4(lst);
	set_all_token(*lst);
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
}

void	go_to_start_lst(t_list **lst)
{
	while (*lst && (*lst)->prev)
		*lst = (*lst)->prev;
}

void	autocomplete(long key, int size_mess, int i, t_token *t)
{
	t_tmp tmp;

	tmp.e = NULL;
	if (!chek_cmd(tmp.left = ft_strndup(g_sel.cmd, g_sel.pos[2])))
		return (ft_strdel(&tmp.left));
	tmp.ws = (tmp.left[g_sel.pos[2] - 1] == 32 ? 1 : 0);
	token_src_1(tmp.left, &t);
	(tmp.ws && (t->type == 1 || t->type == 17)) ? get_fd(&tmp.e, NULL) : 0;
	(!tmp.ws && t && t->type == 17) ? get_fd(&tmp.e, t->content) : 0;
	(!tmp.ws && t && t->type == 1) ? get_bin(&tmp.e, t->content, -1, NULL) : 0;
	tmp.right = ft_strdup(g_sel.cmd + g_sel.pos[2]);
	while (tmp.e && key == TAB)
	{
		t->type = tmp.ws;
		i = pr_autoc(t, ft_strjoin(" ", tmp.right), tmp.e->name, size_mess);
		tmp.e->next ? tmp.e = tmp.e->next : go_to_start_lst(&tmp.e);
		key = 0;
		read(0, &key, 8);
	}
	free_all(tmp, t);
	check_key(key, size_mess, i);
}
