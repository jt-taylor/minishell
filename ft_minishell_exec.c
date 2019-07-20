/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:29:51 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/19 22:04:13 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"

/*
** this will fork the process to run the commands
*/

static int		minishell_run_command()//take path to binary && arguments)
{
	pid_t	pid;

	//fork
	//run signal for the forked process
	// if pid == 0 (ie is forked process)
	//		run it with execve
	//else
	//	cleanup
	return (1)//? not sure what i want to do for the eror checking
}

int		minishell_execute(char **command_list)
{
	//handle builtin function
	//handle $PATH functions
	
	//check permissions with stat / lstat
	//then call run_command
}
