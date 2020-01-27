/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:35:33 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 11:42:34 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	set_first_token(t_token *head)
{
	char *tmp;

	if (head->content[0] == '\'' || head->content[0] == '"')
	{
		tmp = ft_strndup(head->content + 1, (int)ft_strlen(head->content) - 2);
		ft_strdel(&head->content);
		head->content = ft_strdup(tmp);
		ft_strdel(&tmp);
		head->type = 1;
	}
}

void	set_all_token(t_token *hed)
{
	while (hed)
	{
		if (hed->type == 0 && hed->prev)
		{
			if (hed->prev->type == 1 || hed->prev->type == 17)
				hed->type = 17;
			else if (hed->prev->type == 3 || hed->prev->type == 4 ||
				hed->prev->type == 8 || hed->prev->type == 9)
				hed->type = 1;
			else if (ft_is_dir(hed->prev->type))
				hed->type = 16;
		}
		else if (hed->type == 0 && !hed->prev)
			hed->type = 1;
		else if (!hed->prev && hed->type == 17)
			set_first_token(hed);
		hed = hed->next;
	}
}

char	*run_heredoc(char *str)
{
	int		fd;
	t_scanf	*q;

	g_sel.savetty = get_default_settings();
	fd = open("/tmp/heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	while (42 && !g_sel.f)
	{
		ft_putstr_fd("myheredoc> ", 1);
		q = new_scanf(0, ft_strlen("myheredoc> "));
		(q->cmd && ft_strcmp(q->cmd, str)) ? ft_putendl_fd(q->cmd, fd) : 0;
		(!q->cmd && q->key == 10) ? ft_putendl_fd("\n", fd) : 0;
		if ((!q->cmd && q->key == 4) ||
			(q->cmd && !ft_strcmp(q->cmd, str)) || g_sel.f)
			break ;
		ft_putchar_fd('\n', 1);
		q ? ft_strdel(&q->cmd) : 0;
		q ? free(q) : 0;
	}
	res_default_settings(g_sel.savetty);
	fd ? close(fd) : 0;
	q ? ft_strdel(&q->cmd) : 0;
	q ? free(q) : 0;
	return (g_sel.f ? "" : "/tmp/heredoc");
}

void	check_token4(t_token **lst)
{
	t_token	*tmp;
	char	*filename;

	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp && tmp->next && tmp->next->next)
	{
		if ((tmp->next->type == 10 || tmp->next->type == 6) && tmp->next->next)
		{
			tmp->next->type == 10 ?
			filename = ft_strdup(run_heredoc(tmp->next->next->content)) : 0;
			tmp->next->type == 6 ?
			filename = ft_strdup(tmp->next->next->content) : 0;
			free_lst(tmp->next->next);
			ft_strdel(&tmp->next->content);
			tmp->next->content = ft_strdup(filename);
			tmp->next->type = 17;
			ft_strdel(&filename);
		}
		tmp = tmp->next;
	}
	g_sel.f = 0;
}

int		token_main(char *str, t_token **lst)
{
	int	size_token;
	int	i;

	size_token = 1;
	i = 0;
	if (!str)
		return (1);
	while (size_token > 0 && *(str + i))
	{
		if ((size_token = get_token_size(str + i)) == -1)
		{
			ft_strdel(&str);
			return (0);
		}
		*(str + i) != 32 ?
		add_token_lst(lst, creat_token(str + i, size_token, NULL)) : 0;
		i = i + size_token;
	}
	ft_strdel(&str);
	while (*lst && (*lst)->prev)
		*lst = (*lst)->prev;
	check_token4(lst);
	set_all_token(*lst);
	return (validity_test(lst));
}
