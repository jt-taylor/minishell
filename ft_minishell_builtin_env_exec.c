/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_builtin_env_exec.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:27:05 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/09 14:27:08 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** this is a copy of ft_minishell_exec but modified to take a char** for
** instead of the g_env variable
*/

static int		env_minishell_run_command(char *path, char **args, char **envv)
{
	pid_t	pid;

	pid = fork();
	signal(SIGINT, process_signal_handle);
	if (pid == 0)
	{
		(execve(path, args, envv) == -1) ? exit(0) : 0;
	}
	else if (pid < 0)
	{
		ft_putstr("Fork filed -- create new process\n");
		return (-1);
	}
	wait(&pid);
	return (1);
}

/*
** check for builtin commands
*/

static int		env_minishell_check_builtins(char *str)
{
	int	i;

	i = 0;
	while ((unsigned long)i < sizeof(*g_minishell_builtin_list))
	{
		if (g_minishell_builtin_list[i][0] == '\0')
			break ;
		if (ft_strcmp(str, g_minishell_builtin_list[i]) == 0)
			return (i);
		else
			i++;
	}
	return (-1);
}

static char		*env_ft_strjoin_path(char *s1, char *s2, int opt)
{
	int		i;
	char	*tmp;

	(void)opt;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	if (s1[i - 1] != '/')
		tmp = ft_strjoin_free(s1, "/", 0);
	tmp = ft_strjoin_free(tmp, s2, 1);
	return (tmp);
}

/*
** check $path
*/

static int		env_check_path(char **command_list, char *command_name,
		char **envv)
{
	int			i;
	char		*binary_path;
	char		**path_array;
	struct stat	s;

	path_array = ft_strsplit(get_env_variable("PATH"), ':');
	i = -1;
	while (path_array && path_array[++i])
	{
		if (ft_strstart_w_str(command_name, path_array[i]))
			binary_path = ft_strdup(command_name);
		else
			binary_path = env_ft_strjoin_path(path_array[i], command_name, 0);
		if (lstat(binary_path, &s) == -1)
			free(binary_path);
		else
		{
			env_minishell_run_command(binary_path, command_list, envv);
			ft_freestrarr(path_array);
			free(binary_path);
			return (1);
		}
	}
	ft_freestrarr(path_array);
	return (0);
}

/*
** the string is already split so we can skip that part
*/

int				env_minishell_execute(char **command_list, char **envv)
{
	char		**str;
	int			i;
	struct stat	l;

	str = command_list;
	if ((i = (env_minishell_check_builtins(str[0]))) != -1)
	{
		g_builtin_jumptable[i](str, str[0]);
	}
	else if (env_check_path(str, str[0], envv))
	{
		;
	}
	else
	{
		if (lstat(str[0], &l) == 0)
			env_minishell_run_command(str[0], str, envv);
		else
			ft_dprintf(2, "%s: command not found\n", str[0]);
	}
	return (0);
}
