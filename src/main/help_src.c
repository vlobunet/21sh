/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_src.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:59:11 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/11 11:59:15 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	print_part1(void)
{
	ft_putstr_fd("╔══════════════════╦═══════════════════════════════════", 1);
	ft_putstr_fd("══════════════════╗\n║        KEY       ║              ", 1);
	ft_putstr_fd("    ACT/FUNC                           ║\n╠════════════", 1);
	ft_putstr_fd("══════╩════════════════════════════════════════════════", 1);
	ft_putstr_fd("═════╣\n║                             MANAGEMENT OF THE", 1);
	ft_putstr_fd(" COURSE                   ║\n╠══════════════════╦══════", 1);
	ft_putstr_fd("═══════════════════════════════════════════════╣\n║ up.", 1);
	ft_putstr_fd("............. ║ Up one line/story up.                  ", 1);
	ft_putstr_fd("             ║\n║ down............ ║ Down one line / st", 1);
	ft_putstr_fd("ory down.                         ║\n║ right...........", 1);
	ft_putstr_fd(" ║ Right to one character.                             ", 1);
	ft_putstr_fd("║\n║ left............ ║ Left to one character.         ", 1);
	ft_putstr_fd("                     ║\n║ alt+right....... ║ Right to o", 1);
	ft_putstr_fd("ne word.                                  ║\n║ alt+left", 1);
	ft_putstr_fd("........ ║ Left to one word.                           ", 1);
	ft_putstr_fd("        ║\n║ home............ ║ at the beginning of the", 1);
	ft_putstr_fd(" line.                       ║\n║ end............. ║ at", 1);
	ft_putstr_fd(" the end of the line.                             ║\n║ ", 1);
	ft_putstr_fd("tab............. ║ autocomplate.                       ", 1);
	ft_putstr_fd("                ║\n║ backspace....... ║ removes a chara", 1);
	ft_putstr_fd("cter or selected part of a string    ║\n╠══════════════", 1);
	ft_putstr_fd("════╩══════════════════════════════════════════════════", 1);
	ft_putstr_fd("═══╣\n║                              SELECTION MANAGEME", 1);
	ft_putstr_fd("NT                      ║\n╠══════════════════╦════════", 1);
	ft_putstr_fd("═════════════════════════════════════════════╣\n", 1);
}

void	print_part2(void)
{
	ft_putstr_fd("║ alt+shift+right. ║ select / deselect the left word.  ", 1);
	ft_putstr_fd("                  ║\n║ alt+shift+left.. ║ select / dese", 1);
	ft_putstr_fd("lect the right word.                   ║\n║ shift+right", 1);
	ft_putstr_fd("..... ║ select / deselect left symbol.                 ", 1);
	ft_putstr_fd("     ║\n║ shift+left...... ║ select / deselect right sy", 1);
	ft_putstr_fd("mbol.                     ║\n║ shift+home...... ║ selec", 1);
	ft_putstr_fd("t / deselect before the beginning of the line. ║\n║ shi", 1);
	ft_putstr_fd("ft+end....... ║ select / deselect to the end of the lin", 1);
	ft_putstr_fd("e.           ║\n║ alt+a........... ║ select an entire r", 1);
	ft_putstr_fd("ow.                               ║\n╠═════════════════", 1);
	ft_putstr_fd("═╩═════════════════════════════════════════════════════", 1);
	ft_putstr_fd("╣\n║                                  COPY / INSERT    ", 1);
	ft_putstr_fd("                     ║\n╠══════════════════╦═══════════", 1);
	ft_putstr_fd("══════════════════════════════════════════╣\n║ alt+x...", 1);
	ft_putstr_fd("........ ║ cut the selection.                          ", 1);
	ft_putstr_fd("        ║\n║ alt+c........... ║ copy the selection.    ", 1);
	ft_putstr_fd("                             ║\n║ alt+v........... ║ pa", 1);
	ft_putstr_fd("ste copied text.                                  ║\n╚═", 1);
	ft_putstr_fd("═════════════════╩═════════════════════════════════════", 1);
	ft_putstr_fd("════════════════╝\n\n╔══════════════════╦══════════════", 1);
	ft_putstr_fd("═══════════════════════════════════════╗\n║      COMMAN", 1);
	ft_putstr_fd("D     ║                  ACT/FUNC                      ", 1);
	ft_putstr_fd("     ║\n╠══════════════════╬═══════════════════════════", 1);
	ft_putstr_fd("══════════════════════════╣\n", 1);
}

void	print_part3(void)
{
	ft_putstr_fd("║ env............. ║ print environment                 ", 1);
	ft_putstr_fd("                  ║\n║ setenv.......... ║ set environme", 1);
	ft_putstr_fd("nt.                                    ║\n║ unsetenv...", 1);
	ft_putstr_fd("..... ║ delete environment.                            ", 1);
	ft_putstr_fd("     ║\n║ clear........... ║ clear the terminal screen.", 1);
	ft_putstr_fd("                          ║\n║ cd.............. ║ switc", 1);
	ft_putstr_fd("h between directories.                         ║\n║ ech", 1);
	ft_putstr_fd("o............ ║ write arguments to the standard output.", 1);
	ft_putstr_fd("             ║\n║ exit............ ║ exit 21sh.        ", 1);
	ft_putstr_fd("                                  ║\n║ help............", 1);
	ft_putstr_fd(" ║ display help file.                                  ", 1);
	ft_putstr_fd("║\n╚══════════════════╩════════════════════════════════", 1);
	ft_putstr_fd("═════════════════════╝\n\n      if you want to find out", 1);
	ft_putstr_fd(" more about how to use the command use:\n              ", 1);
	ft_putstr_fd("          myman [command]\n\n", 1);
}

void	run_help(void)
{
	print_part1();
	print_part2();
	print_part3();
}
