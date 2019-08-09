/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:29:51 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/09 12:24:01 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		minishell_run_command(char *path, char **args)
{
	pid_t	pid;

	pid = fork();
	signal(SIGINT, process_signal_handle);
	if (pid == 0)
	{
		(execve(path, args, g_env) == -1) ? exit(0) : 0;
	}
	else if (pid < 0)
	{
		ft_putstr("Fork failed -- create new process\n");
		// do i need to exit here ?
		exit(0);
		return (-1);
	}
	wait(&pid);
	return (1);
}

/*
** check for builtin commands
*/

static int		minishell_check_builtins(char *str)
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

static char		*ft_strjoin_path_free(char *s1, char *s2, int opt)
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

static int		check_path(char **command_list, char *command_name)
{
	int			i;
	char		*binary_path;
	char		**path_array;
	struct stat	s;

	path_array = (get_env_variable("PATH")) ?
		ft_strsplit(get_env_variable("PATH"), ':') : NULL;
	i = -1;
	while (path_array && path_array[++i])
	{
		if (ft_strstart_w_str(command_name, path_array[i]))
			binary_path = ft_strdup(command_name);
		else
			binary_path = ft_strjoin_path_free(path_array[i], command_name, 0);
		if (lstat(binary_path, &s) == -1)
			free(binary_path);
		else
		{
			minishell_run_command(binary_path, command_list);
			ft_freestrarr(path_array);
			free(binary_path);
			return (1);
		}
	}
	ft_freestrarr(path_array);
	return (0);
}

int				minishell_execute(char **command_list)
{
	char		**str;
	int			i;
	struct stat	l;

	str = ft_strsplit(*command_list, ' ');
	if ((i = (minishell_check_builtins(str[0]))) != -1)
	{
		g_builtin_jumptable[i](str, str[0]);
	}
	else if (check_path(str, str[0]))
	{
		;
	}
	else
	{
		if (lstat(str[0], &l) == 0)
			minishell_run_command(str[0], str);
		else
			ft_dprintf(2, "%s: command not found\n", str[0]);
	}
	ft_freestrarr(str);
	return (0);
}
