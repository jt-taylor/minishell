/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 09:33:50 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/11 19:13:17 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

/*
** this will be used as the global env variable for processes to inherit
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


#endif
