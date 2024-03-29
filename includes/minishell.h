/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 09:33:50 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/09 21:22:10 by jtaylor          ###   ########.fr       */
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

/*
** MACROS
*/

# define MINISHELL_BUF_SIZE 1024
# define GENV_VAR get_env_variable

/*
** all of the glabal vars
*/
char						**g_env;

# ifndef MINISHELL_BUILTIN_LIST
#  define MINISHELL_BUILTIN_LIST

extern char					*g_minishell_builtin_list[];

# endif

/*
** ft_minishell_parse_env.c
*/
void						ft_minishell_printenv(char **args, char *str);
void						ft_minishell_parse_env(char **env);
char						*get_env_variable(char *var_name);
int							grab_env_len(char **env);
char						**empty_envv(char **envv);

/*
** ft_minishell_prompt.c"
*/
void						ft_minishell_exit_shell(void);
void						ft_shell_print_prompt(void);

/*
** ft_minishell_siganl_handle.c
*/
void						process_signal_handle(int sig);
void						minishell_signal_handle(int signum);

/*
** ft_shell_process_input.c
*/
int							minishell_parse_input(char **raw_input,
								char **parsed);

/*
** ft_minishell_exec.c
*/
int							minishell_execute(char **command_list);

/*
** ft_minishell_exit.c
*/
void						builtin_exit(char **args, char *str);

/*
** ft_minishell_unsetenv.c
*/
void						builtin_unsetenv(char **args, char *value);

/*
** ft_minishell_builtin_env.c
*/
void						builtin_env(char **args, char *value);

/*
** ft_minishell_env
*/
void						builtin_setenv(char **arg, char *str);

/*
** ft_minishell_cd.c
*/
void						builtin_cd(char **args, char *str);

/*
** ft_minishell_builtin_env_exec.c
*/
int							env_minishell_execute(char **command_list,
								char **envv);

/*
** ft_minishell_builtin_env_setenv.c
*/
void						env_builtin_setenv(char **arg, char *str,
								char **envv);

/*
** ft_minishell_builtin_echo.c
*/
void						builtin_echo(char **args, char *str);

/*
** for builtins && their jumptable
*/
typedef void				t_builtin_jumptable(char **args, char *str);
extern t_builtin_jumptable	*g_builtin_jumptable[];
#endif
