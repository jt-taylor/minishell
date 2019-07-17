/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_parse_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:45:23 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/12 12:49:59 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
** this will print the env variables // printenv without the -0 option
*/

void			ft_minishell_printenv(char **env, char c)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putstr(env[i++]);
		write(1, &c, 1);
	}
}

/*
** returns the length of the shell envirement
*/

static int		grab_env_len(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		;
	return (i + 1);
}

void	ft_minishell_parse_env(char **env)
{
	int		i;

	i = -1;
	g_env = (char **)malloc(sizeof(char *) * (grab_env_len(env) + 1));
	while (env[++i])
		if (!(g_env[i] = ft_strdup(env[i])))
			ft_minishell_exit_shell();
}
