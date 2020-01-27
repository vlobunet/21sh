/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 09:46:17 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/14 20:13:57 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	print_error_term(void)
{
	ft_putstr_fd("ERROR: The device is not a terminal!\n", 2);
	exit(EXIT_FAILURE);
}

void	print_error_data(int i)
{
	if (i == -1)
		ft_putstr_fd("ERROR: Description of the \
			current terminal was not found!\n", 2);
	else if (i == 0)
		ft_putstr_fd("ERROR: Description of the current terminal empty!\n", 2);
	exit(EXIT_FAILURE);
}

void	print_error_quote(void)
{
	ft_putendl_fd("\n21sh: unexpected EOF while looking for matching `\"'", 2);
	ft_putendl_fd("21sh: syntax error: unexpected end of file", 2);
}

int		ft_err_message(char *s)
{
	if (s)
	{
		ft_putstr_fd("21sh: syntax error  ", 2);
		ft_putstr_fd(s, 2);
	}
	else
		ft_putstr_fd("zsh: parse error ", 2);
	ft_putstr_fd("\n", 2);
	return (-1);
}
