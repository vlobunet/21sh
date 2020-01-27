/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_src_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:34:23 by vlobunet          #+#    #+#             */
/*   Updated: 2018/07/29 10:34:25 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		ft_ch_sumb(char *str, char s)
{
	while (*str)
		if (s == *str++)
			return (1);
	return (0);
}

int		cheak_atr(char **cmd_attr, t_param *lst_pr)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	while (cmd_attr[j])
	{
		while (cmd_attr[j][i])
		{
			if (ft_ch_sumb("eEnbiu", cmd_attr[j][i]))
			{
				lst_pr->i = (cmd_attr[j][i] == 'i' ? 1 : lst_pr->n);
				lst_pr->u = (cmd_attr[j][i] == 'u' ? 1 : lst_pr->b);
			}
			else
			{
				error_arg(cmd_attr[j][i]);
				return (0);
			}
			i++;
		}
	}
	return (1);
}
