/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:27:37 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/09 20:53:03 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** okay so there are actually a few versions of env that do different things
** env can just print the envirement variables or
** launch a program//binary with specified envirement variables
** change or remove envirement variables
** used by shell scripts ot launch interpreters
**
** so im not really sure what specific feature this wants , im assumeing
** that it just wants to the printing of the envirement variables
** as it also wants setenv and unsetenv and it doesn't make sense
** that it would want me to hardcode two entrypoints to the same functionality;
*/

/*
** this will read everythipng preceding the '=' from index into a temp string
** append the '=' to the temp string,
** append the
*/

static char		*env_set_value(char *index, char *value)
{
	char	*tmp;
	int		len;

	len = 0;
	while (index[len] != '=' && index[len])
		len++;
	tmp = ft_strdup(index);
	ft_bzero(tmp, ft_strlen(index));
	tmp = ft_strncpy(tmp, index, (size_t)len);
	free(index);
	tmp = ft_strjoin_free(tmp, "=", 1);
	index = ft_strjoin_free(tmp, value, 1);
	return (index);
}

/*
** reallocates a new char ** to hold an aditional string for the enc array
*/

static char		**ft_env_array_realloc(char **args, char *value)
{
	char	**tmp;
	int		i;

	i = 0;
	while (g_env[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (g_env[i])
	{
		if (!(tmp[i] = ft_strdup(g_env[i])))
			;
		i++;
	}
	ft_freestrarr(g_env);
	tmp[i] = ft_strjoin(args[1], "=");
	tmp[i] = ft_strjoin_free(tmp[i], value, 1);
	tmp[++i] = NULL;
	return (tmp);
}

static void		ft_check_env_var(char **args, char *value)
{
	int		i;

	i = 0;
	while (g_env[i] && g_env[i][0])
	{
		if (ft_strstart_w_str(g_env[i], args[1]))
		{
			g_env[i] = env_set_value(g_env[i], value);
			return ;
		}
		i++;
	}
	g_env = ft_env_array_realloc(args, value);
}

/*
** this will set a env VARIABLE to the passed value
** this is pretty simple because i'm using a global char **
** to store the var value pairs
*/

void			builtin_setenv(char **arg, char *str)
{
	char	*null_string;

	null_string = "";
	(void)str;
	if (!arg[1])
		ft_minishell_printenv(arg, "");
	else if (!arg[2])
		ft_check_env_var(arg, null_string);
	else
		ft_check_env_var(arg, arg[2]);
}
