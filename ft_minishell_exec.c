/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:29:51 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/25 12:49:35 by jtaylor          ###   ########.fr       */
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

/* check for builtin commands
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

int		minishell_execute(char **command_list)
{
	char **str;
	int		i;
	//testing
	str = ft_strsplit(*command_list, ' ');//here we should split the string into its own array
	//handle builtin function
	if ((i = (minishell_check_builtins(str[0]))) != -1)
	{
		ft_printf("is a builtin , need to build the builtin\n");
	}
	//handle $PATH functions
	//check permissions with stat / lstat
	//then call run_command
	//testing
	//ohh a new errir with gcc unsequenced modifacation and acess to command_list
		//minishell_run_command(*command_list, command_list++);
	//ft_printf("%s\n", str[0]);
	else
		minishell_run_command(str[0], str);
	ft_freestrarr(str);
	return (0);
}
