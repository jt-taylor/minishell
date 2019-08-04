/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_parse_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:45:23 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/03 14:47:07 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** this should return the only the path env variable
*/

char	*get_env_variable(char *var_name)
{
	int		i;
	char	*tmp;

	i = 0;
	while (g_env[i])
	{
		tmp = ft_strjoin(var_name, "=");
		if (ft_strstart_w_str(g_env[i], tmp))
		{
			free(tmp);
			return (ft_strchr(g_env[i], '=') + 1);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

/*h
void			ft_minishell_printenv(char **env, char c)
** {
** 	int		i;
** 
** 	i = 0;
** 	while (env[i])
** 	{
** 		ft_putstr(env[i++]);
** 		write(1, &c, 1);
** 	}
** }
*/

/*
** this is redudndent , printenv is in the $path
*/

void		ft_minishell_printenv(char **args, char *str)
{
	int		i;

	(void)str;
	(void)args;
	i = -1;
	while (g_env[++i])
	{
		ft_putstr(g_env[i]);
		write(1, "\n", 1);
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

/*
** this parses the env variables into the g_env global array
*/

void	ft_minishell_parse_env(char **env)
{
	int		i;

	i = -1;
	//do we need to malloc a global , internet says global bad which is
	g_env = (char **)malloc(sizeof(char *) * (grab_env_len(env) + 1));
	while (env[++i])
		if (!(g_env[i] = ft_strdup(env[i])))
			ft_minishell_exit_shell();
}
