/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 09:33:50 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/29 17:10:50 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <sys/stat.h>
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

// 			Testing zone
//testing for fork depth
int		depth;

/*
** MACROS
*/

# define MINISHELL_BUF_SIZE 1024

/*
** all of the glabal vars
*/
char					**g_env;
# ifndef minishell_builtin_list
#  define minishell_builtin_list

extern char					*g_minishell_builtin_list[];

# endif

/*
** ft_minishell_parse_env.c
*/
void			ft_minishell_printenv(char **env, char c);
void			ft_minishell_parse_env(char **env);
char			*get_env_variable(char *var_name);

/*
** ft_minishell_prompt.c"
*/

void	ft_minishell_exit_shell(void);
void		ft_shell_print_prompt(void);

/*
** ft_minishell_siganl_handle.c
*/

void		process_signal_handle(int sig);
void		minishell_signal_handle(int signum);

/*
** ft_shell_process_input.c
*/

int		minishell_parse_input(char **raw_input, char **parsed);

/*
** ft_minishell_exec.c
*/

int		minishell_execute(char **command_list);

#endif
