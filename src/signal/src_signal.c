/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 08:52:32 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/15 19:28:46 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	init_signal(void)
{
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	init_shell(void)
{
	struct sigaction act;

	ft_memset(&act, '\0', sizeof(act));
	act.sa_flags = 0;
	act.sa_handler = &get_sigint;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGWINCH, &act, NULL);
}

void	signal_dfl(void)
{
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
