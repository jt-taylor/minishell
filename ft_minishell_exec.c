/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:29:51 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/29 21:06:35 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
** this will fork the process to run the commands
** this forks no matter what so all of the validation for the execve executables
** has to happen before this is called
**
*/

static int		minishell_run_command(char *path, char **args)//take path to binary && arguments)
{
	pid_t	pid;

	//fork
	pid = fork();
	//run signal for the forked process
	signal(SIGINT, process_signal_handle);
	// if pid == 0 (ie is forked process)
	//		run it with execve
	if (pid == 0)
	{
		execve(path, args, g_env);
		//kill ?
	}
	//else if (error check)
	else if (pid < 0)
	{
		ft_putstr("Fork filed -- create new process\n");
		return (-1);
	}
	// free ?
	wait(&pid);
	//	cleanup
	//testing
	depth++;
	printf("\nDepth = %d\n", depth);
	//so the problem here is that we want to kill any of the new forks
	//but not the original, or just not pass it here if
	//it won't get to execve();
	//kill(pid, SIGKILL);
	return (1);//? not sure what i want to do for the eror checking
}

/*
** check for builtin commands
*/

static int		minishell_check_builtins(char *str)
{
	int	i;

	i = 0;
	ft_printf("size of global = : %d\n", sizeof(*g_minishell_builtin_list));
	while ((unsigned long)i < sizeof(*g_minishell_builtin_list))
	{
		if (g_minishell_builtin_list[i][0] == '\0')
			break ;
		if (ft_strcmp(str, g_minishell_builtin_list[i]) == 0)
			return (i);
		else
			i++;
	}
	ft_printf("size = %d\n", i);
	return (-1);
}

static char		*ft_strjoin_path_free(char *s1, char *s2, int opt)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	if (s1[i - 1] != '/')
		s1 = ft_strjoin_free(s1, "/", 1);
	s1 = ft_strjoin_free(s1, s2, opt);
	return (s1);
}

/*
** check $path
*/
static int	check_path(char **command_list, char *command_name)
{
	int			i;
	char		*binary_path;
	char		**path_array;
	struct stat	s;

	path_array = ft_strsplit(get_env_variable("PATH"), ':');
	i = 0;
	while (path_array && path_array[i])
	{
		//if command is found in path binary_path = command[0]
		//	/bin/absolute/path
		if (ft_strstart_w_str(command_name, path_array[i]))
			binary_path = ft_strdup(command_name);
		//else
		//	append command[0] to path then check
		else
			binary_path = ft_strjoin_path_free(path_array[i], command_name, 0);
			;//binary_path = strjoin paths (path[i] && command_name);
		//lstat
		//	?free
		if (lstat(binary_path, &s) == -1)
		{
			ft_printf("value of errno = %d\nbinary_path = %s\n", errno, binary_path);
			free(binary_path);
		}
		//else
		//	free path array
		//	return (check if executable);
		else
		{
			//path array should be malloc'd here unless my array_free is going out of the index??
			//ft_freestrarr(path_array);
			ft_printf("command_name before : %s\n", command_name);
			command_name = binary_path;
			ft_printf("command_name after : %s\n", command_name);
			return (1);//check if executable)
		}
		i++;
	}
	//free path_array;
	//Pretty sure either my free path array is broken ?? or im not allocating for the array in strsplit??
	//for right now i am just not gonna free it , remember to go back and free everything otherwise
	//extended use will break it 
	//ft_freestrarr(path_array);
	//test
	if (command_list)
		;
	//
	ft_printf("after : %s\n", binary_path);
	return (0);
}

int		minishell_execute(char **command_list)
{
	char **str;
	int		i;
	//testing
	str = ft_strsplit(*command_list, ' ');//here we should split the string into its own array
	ft_printf("str[0] == '%s'", str[0]);
	//handle builtin function
	if ((i = (minishell_check_builtins(str[0]))) != -1)
	{
		//am going to use the return from checkbuiltins as the index in a branch table 
		//to pass to the builtin function
		ft_printf("is a builtin , need to build the builtin\n");
	}
	//handle $PATH functions
	else if (check_path(command_list, str[0]))//check $path)
	{
		//
		ft_printf("'else if' command string here is %s\n", str[0]);
		minishell_run_command(str[0], str);
	}
	//check permissions with stat / lstat
	//then call run_command
	//testing
	//ohh a new errir with gcc unsequenced modifacation and acess to command_list
		//minishell_run_command(*command_list, command_list++);
	//ft_printf("%s\n", str[0]);
	else
	{
		//
		ft_printf("str[0] == '%s'", str[0]);
		minishell_run_command(str[0], str);
	}
	ft_freestrarr(str);
	return (0);
}
