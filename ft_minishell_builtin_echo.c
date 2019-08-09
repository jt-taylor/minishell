/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_builtin_echo.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:08:29 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/09 00:11:16 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	builtin_echo_print(char *argument, int last)
{
	if (ft_strcmp("~", argument) == 0)
	{
		ft_putstr(get_env_variable("HOME"));
		return ;
	}
	if (argument[0] == '$')
		ft_putstr(get_env_variable(argument + 1));
	else
		ft_putstr(argument);
	if (!last)
		write(1, " ", 1);
}

void		builtin_echo(char **args, char *str)
{
	int		i;

	(void)str;
	i = 0;
	if (args[++i])
		while (args[i])
		{
			builtin_echo_print(args[i], (args[i + 1]) ? 1 : 0);
			i++;
		}
	write(1, "\n", 1);
}
