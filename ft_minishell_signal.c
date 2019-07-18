/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_signal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:55:35 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/18 11:48:13 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** signal (3) is really interesting
**
** at a very basic level signal (3) is a pretty wrapper for sigaction (2)
** you pass it a bitmask for which signal you are going to handle
** and it makes a new thread that listens for that signal
** ie [ signal(signal_mask, function_pointer) ]
**
** the man for signal (3) and sigaction (2) was very informative and will
** explain how this works much better than i would have
*/

/*
** this handles the signal values for the minishell program , will make a diff
**		function for handling signals on the processes
** ie	C-c // ctrl-c
*/

void		minishell_signal_handle(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		ft_shell_display_prompt();
		signal(SIGINT, minishell_signal_handle);
	}
}
