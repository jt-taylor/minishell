/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_builtin_env.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:05:32 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/10 11:34:20 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			**envirement_array_dupe(void)
{
	char	**envv;
	int		i;

	i = -1;
	envv = (char **)malloc(sizeof(char *) * (grab_env_len(g_env) + 1));
	while (g_env[++i])
		if (!(envv[i] = ft_strdup(g_env[i])))
			ft_minishell_exit_shell();
	envv[i] = NULL;
	return (envv);
}

static inline void	builtin_env_handle_args(int *i, int point, char **args)
{
	while (args[++*i])
	{
		point = *i;
		if (args[*i][1] == 'u' && args[*i][0] == '-' && !args[*i][2])
			(*(args + ++*i)) ?
				builtin_unsetenv(args + point, args[*i]) : 0;
		else if (args[*i][0] == '-' && args[*i][1] == 's')
			(*(args + point) && *(args + *i + 2) && !args[*i][2]) ?
			builtin_setenv(args + point, args[*i += 2]) :
			ft_dprintf(2, "-s requires the format : -s [name] [value]\n");
		else if (args[*i][0] == '-' && !args[*i][1])
			g_env = empty_envv(g_env);
		else
			break ;
	}
}

/*
** so either i rewrite the exec functions to take char ** as an input and just
** pass g_env as the paramenter
** or copy g_env and change that then at the end
** set g_env to a copy of the original
**
** gonan have to set g_env to the new envv then set it back cause im a dummy
*/

void				builtin_env(char **args, char *value)
{
	int		i;
	int		point;
	char	**tmp;
	char	**envv;

	i = 0;
	point = 0;
	tmp = args;
	if (!args[1])
	{
		ft_minishell_printenv(args, args[0]);
		return ;
	}
	envv = envirement_array_dupe();
	(void)value;
	builtin_env_handle_args(&i, point, args);
	if (!(*(args + i)))
		ft_minishell_printenv(args + i, *(args + i));
	else
		env_minishell_execute(args + i, g_env);
	ft_freestrarr(g_env);
	g_env = envv;
}
