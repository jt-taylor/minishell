/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:29:51 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/23 16:52:40 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** this will fork the process to run the commands
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
		(path) ? free(path) : 0;
		ft_putstr("Fork filed -- create new process\n");
		return (-1);
	}
	// free ?
	wait(&pid);
	if (path)
		free(path);
	//	cleanup
	return (1);//? not sure what i want to do for the eror checking
}

int		minishell_execute(char **command_list)
{
	char *str;
	//testing
	if (command_list)
		;
	//handle builtin function
	//handle $PATH functions
	
	//check permissions with stat / lstat
	//then call run_command
	//testing
	//ohh a new errir with gcc unsequenced modifacation and acess to command_list
		//minishell_run_command(*command_list, command_list++);
	str = *command_list;
		minishell_run_command(str, command_list++);
	return (0);
}
