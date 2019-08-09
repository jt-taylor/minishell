/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_builtin_env.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:05:32 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/08 23:42:52 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**envirement_array_dupe(void)
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

//static char		**env_ft_env_array_remove_realloc(int index, char **envv)
//{
//	char	**tmp;
//	int		i;
//	int		j;
//
//	j = 0;
//	i = 0;
//	while (envv[i])
//		i++;
//	tmp = (char **)malloc(sizeof(char *) * i);
//	i = 0;
//	while (envv[i])
//	{
//		if (i == index)
//		{
//			i++;
//			continue;
//		}
//		if (!(tmp[j] = ft_strdup(envv[i])))
//			;
//		i++;
//		j++;
//	}
//	ft_freestrarr(envv);
//	tmp[i] = NULL;
//	return (tmp);
//}

//static void			env_builtin_unsetenv(char **args, char *value, char **envv)
//{
//	int		i;
//
//	(void)value;
//	i = 0;
//	if (value == args[1])
//	{
//		while (envv[i])
//		{
//			if (ft_strstart_w_str(envv[i], args[1]))
//				break ;
//			i++;
//		}
//	}
//	else
//	{
//		while (envv[i])
//		{
//			if (ft_strstart_w_str(envv[i], args[1]))
//				break ;
//			i++;
//		}
//	}
//	if (envv[i])
//		envv = env_ft_env_array_remove_realloc(i, envv);
//}

static void		empty_envv(char **envv)
{
	ft_freestrarr(envv);
	envv = (char **)malloc(sizeof(char *) * 2);
	//does this break it ??
	//envv = NULL;
	envv[0] = ft_strdup("");
}

/*
** so either i rewrite the exec functions to take char ** as an input and just
** pass g_env as the paramenter
** or copy g_env and change that then at the end set g_env to a copy of the original
**
**
** gonan have to set g_env to the new envv then set it back cause im a dummy
*/

void	builtin_env(char **args, char *value)
{
	int		i;
	int		point;
	char	**tmp;
	char	**envv;

	i = 0;
	tmp = args;
	if (!args[1])
	{
		ft_minishell_printenv(args, args[0]);
		return ;
	}
	envv = envirement_array_dupe();
	(void)value;
	while (args[++i])
	{
		point = i;
		if (args[i][1] == 'u' && args[i][0] == '-')
			builtin_unsetenv(args + point, args[++i]);
		else if (args[i][0] == '-' && args[i][1] == 's')
			builtin_setenv(args + point, args[i += 2]);
		else if (args[i][0] == '-')
			empty_envv(g_env);
		else
			break ;
	}
	env_minishell_execute(args + i, g_env);
	if (g_env)
		ft_freestrarr(g_env);
	g_env = envv;
}
