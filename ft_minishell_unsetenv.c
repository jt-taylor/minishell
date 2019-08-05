/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_unsetenv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:43:44 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/05 13:22:06 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**ft_env_array_remove_realloc(int index)
{
	char	**tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (g_env[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (g_env[i])
	{
		if (i == index)
		{
			i++;
			continue;
		}
		if (!(tmp[j] = ft_strdup(g_env[i])))
			// error allocating
			;
		i++;
		j++;
	}
	ft_freestrarr(g_env);
	return (tmp);
}

void		builtin_unsetenv(char **args, char *value)
{
	int		i;

	(void)value;
	i = 0;
	if (value == args[1])
	{
		while (g_env[i])
		{
			if (ft_strstart_w_str(g_env[i], args[1]))
				break ;
			i++;
		}
	}
	else
	{
		while (g_env[i])
		{
			if (ft_strstart_w_str(g_env[i], value))
				break ;
			i++;
		}
	}
	//ft_printf("args[1] == %s\ng_env[i] == %s\n", args[1], g_env[i]);
	if (g_env[i])
		g_env = ft_env_array_remove_realloc(i);
}
