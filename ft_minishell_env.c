/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:27:37 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/31 17:40:49 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** okay so there are actually a few versions of env that do different things
** env can just print the envirement variables or
** launch a program//binary with specified envirement variables
** change or remove envirement variables
** used by shell scripts ot launch interpreters
**
** so im not really sure what specific feature this wants , im assumeing
** that it just wants to the printing of the envirement variables
** as it also wants setenv and unsetenv and it doesn't make sense
** that it would want me to hardcode two entrypoints to the same functionality;
*/
