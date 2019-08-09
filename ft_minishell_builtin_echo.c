/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_builtin_echo.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:08:29 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/09 11:58:23 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	builtin_echo_no_quotes(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == '\"')
			{
				i++;
				continue ;
			}
			write(1, &str[i], 1);
			i++;
		}
}

static void	builtin_echo_print(char *argument, int last)
{
	if (ft_strcmp("~", argument) == 0)
	{
		builtin_echo_no_quotes(get_env_variable("HOME"));
		return ;
	}
	if (argument[0] == '$')
		builtin_echo_no_quotes(get_env_variable(argument + 1));
	else
		builtin_echo_no_quotes(argument);
	if (last == 1)
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
