/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 09:13:26 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/07 21:04:06 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** the null string at the end is required beacause of how I am handling builtins
** it will access outside the bounds of the array with out it so when you add
** builtins remember to put them before the ""
*/

char					*g_minishell_builtin_list[] =
{ "cd",
	"echo",
	"env",
	"setenv",
	"unsetenv",
	"printenv",
	"exit",
	""
};

void					testing(char **testing, char *str)
{
	(void)testing;
	(void)str;
	ft_printf("wow remember to remove me later\n");
}

/*
** cd,
** echo,
** env,
** setenv,
** unsetenv,
** printenv,
** exit,
** NULL,
*/

t_builtin_jumptable		*g_builtin_jumptable[] =
{
	builtin_cd,
	testing,
	builtin_env,
	builtin_setenv,
	builtin_unsetenv,
	ft_minishell_printenv,
	builtin_exit,
	testing
};

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
*/

static int				minishell_main_loop(char *raw_input, char *tmp,
		char **parsed_input, char **generic_pointer)
{
	int		break_value;

	break_value = 1;
	ft_shell_print_prompt();
	signal(SIGINT, minishell_signal_handle);
	get_next_line(0, &raw_input);
	if (!(break_value = ft_stronly_space(raw_input)))
	{
		free(raw_input);
		return (1);
	}
	tmp = ft_strtrim(raw_input);
	parsed_input = ft_strsplit(tmp, ';');
	generic_pointer = parsed_input;
	while (*parsed_input && **parsed_input != '\0')
	{
		minishell_execute(parsed_input);
		parsed_input++;
	}
	free(raw_input);
	free(tmp);
	ft_freestrarr(generic_pointer);
	return (break_value);
}

/*
** the third option is implementation specific , is a points to an array of
** 		the host env variables , it is also accessible with the global var
*/

int						main(int ac, char **argv, char **env)
{
	char	*raw_input;
	char	*tmp;
	char	**parsed_input;
	char	**generic_pointer;

	raw_input = NULL;
	tmp = NULL;
	parsed_input = NULL;
	generic_pointer = NULL;
	ft_minishell_parse_env(env);
	while (1)
	{
		if (minishell_main_loop(raw_input, tmp, parsed_input,
				generic_pointer) < 0)
			break ;
	}
	if (ac)
		;
	if (argv[1])
		;
	return (0);
}
