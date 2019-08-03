/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_prompt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:53:02 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/02 15:19:19 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_minishell_exit_shell(void)
{
	ft_freestrarr(g_env);
	write(1, "\n", 1);
	exit(0);
}

/*
** why make this a function ?
** so later when the prompt gets fancy i don't have to change it more than once
*/

void		ft_shell_print_prompt(void)
{
	ft_printf("a simple \"$>\"\t->");
}
