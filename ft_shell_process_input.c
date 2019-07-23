/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_process_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:48:38 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/23 14:46:52 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// not really sure how i want t parse the input string
// so far what i am deciding between is either breaking the str into an array
// 	of strings
// or I can tokenize the string and just run the command parser in a loop
//
// not sure which is better yeth


/*
** okay so im not sure why when this is called we need to pass by reference with
** & when most of what i found online says arrays are passed by referenc by default ?
** do i need to just malloc it here ?
*/

int		minishell_parse_input(char **raw_input, char **parsed)
{
	parsed = ft_strsplit(*raw_input, ';');
	// i should either do the expansion here or after i return the command
	// 	str arrays
	//
	return (0);
}
