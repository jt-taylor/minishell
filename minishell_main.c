/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 09:13:26 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/22 16:17:59 by jtaylor          ###   ########.fr       */
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
** this basically just loops through the array of strings and will execute
** the command contained within each one , this is to handle the
int		ft_minishell_exec_commands(//)
{

}
*/

/*
** the third option is implementation specific , is a points to an array of
** 		the host env variables , it is also accessible with the global var
*/

int				main(int ac, char **argv, char **env)
{
	char	*raw_input;
	char	**parsed_input = NULL;//
	int		break_value;

	// load config && envirement variables from input
	ft_minishell_parse_env(env);
	// test
		//ft_minishell_printenv(g_env, '\n');
	//run the command loop
	//testing
	break_value = 1;
	while (1)
	{
		ft_shell_print_prompt();
		signal(SIGINT, minishell_signal_handle);
		//get input
		get_next_line(0, &raw_input);
		//check if input is empty
//		if (ft_stronly_space(*raw_input))
//		{
//			free(raw_input);
//			continue ;
//		}
		// parse input
		// parse into serperate commands bythe ';' charector
		minishell_parse_input(&raw_input, parsed_input);
		ft_putstrarr(parsed_input);
		//execute the command lists
		free(raw_input);
//		break_value = minishell_execute(parsed_input);//execute commands(insert string here);
		//free the command list / array
		//break statement
		if (break_value < 0)
			break ;
	}
	//free global env array
	//more cleanup ?
	//testing
	if (ac)
		;
	if (argv[1])
		;
	return (0);
}
