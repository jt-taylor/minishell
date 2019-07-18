/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 09:33:50 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/17 18:04:02 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include "libft.h"

/*
** MACROS
*/
# define MINISHELL_BUF_SIZE 1024

/*
** all of the glabal vars
*/
char					**g_env;

/*
** ft_minishell_parse_env.c
*/
void			ft_minishell_printenv(char **env, char c);
void			ft_minishell_parse_env(char **env);


/*
** ft_minishell_prompt.c"
*/
void	ft_minishell_exit_shell(void);
void		ft_shell_print_prompt(void);


#endif
