/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:10:44 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/17 16:19:30 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** this will 'explode' the string on whitespaces 
** this is poc , need to readjust this when we add echo '\ escaping'  or quoting
*/

static inline void	line_explode(char **line, char **input)
{
	int		bufsize;
	int		position;
	char	**tokens;
	char	*token;

	bufsize = MINISHELL_BUF_SIZE;
	position = 0;
	if (!(tokens = (char **)malloc(sizeof(char *) * bufsize)))
	{
		ft_dprintf(stderr, "minishell allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = ft_strtok(line, " \n\t\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += MINISHELL_BUF_SIZE;

		}
	}

}

/*
** the main loop of the shell
*/

void	ft_minishell(void)
{
	char	**line;
	char	**input;
	int		status;

	status = 1;
	while (status)
	{
		ft_printf("$> ");
		// read into a line
		get_next_line(&line);
		//split line into an array
		//status = execute;
		//free(?);
	}
}
