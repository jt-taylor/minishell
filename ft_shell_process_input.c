/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_process_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:48:38 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/19 22:04:13 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// not really sure how i want t parse the input string
// so far what i am deciding between is either breaking the str into an array
// 	of strings
// or I can tokenize the string and just run the command parser in a loop
//
// not sure which is better yeth


int		minishell_parse_input(char **raw_input, char **parsed)
{
	parsed = ft_strsplit(*raw_input, ';');
	// i should either do the expansion here or after i return the command
	// 	str arrays

	return (0);
}
