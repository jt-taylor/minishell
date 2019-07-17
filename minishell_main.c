/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 09:13:26 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/12 14:56:42 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** functions allowed within the mandatory part
** ◦ malloc, free
** ◦ access
** ◦ open, close, read, write
** ◦ opendir, readdir, closedir
** ◦ getcwd, chdir
** ◦ stat, lstat, fstat
** ◦ fork, execve
** ◦ wait, waitpid, wait3, wait4
** ◦ signal, kill
** ◦ exit
*/

/*
** See Stephan Brennan's blogpost 'write a shell in c' 16 Jan 2015
*/
/*
** so the structure for the main should look similar to this
** <main>
** 		set up env variables
**
** 		loop to parse && execute commands
**
** 		cleanup
** 		return (Success);
** </main>
**
** and the loop should look like this 
** <loop>
** 	while (command return value)
** 		printf("$>")
** 		get_line()
** 		parse_line()
** 		execute_line()
** </loop>
*/

/*
** the third option is implementation specific , is a points to an array of
** 		the host env variables , it is also accessible with the global var
*/

int				main(int ac, char **argv, char **env)
{
	// load config && envirement variables from input
	ft_minishell_parse_env(env);
	// test
	ft_minishell_printenv(g_env, '\n');

	//run the command loop

	//cleanup ?
	return (0);
}
