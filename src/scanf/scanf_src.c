/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf_src.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:21:41 by vlobunet          #+#    #+#             */
/*   Updated: 2018/07/28 16:21:45 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

char	*full_deletion(char *cmd, int size_mess)
{
	go_to_start_str(size_mess);
	tputs(tgetstr("cd", NULL), 1, printnbr);
	free(cmd);
	return (NULL);
}

char	*del_after_cursor(char *cmd)
{
	char	*str;

	tputs(tgetstr("cd", NULL), 1, printnbr);
	str = ft_strndup(cmd, g_sel.pos[2]);
	free(cmd);
	return (str);
}
