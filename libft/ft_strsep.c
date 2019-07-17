/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:08:06 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/12 16:22:01 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **string_in, char *delim)
{
	char	*begin;
	char	*end;

	begin = *string_in;
	if (begin == NULL)
		return NULL;
	end = begin + ft_strcspn(begin, delim);
	if (*end)
	{
		*end++ = '\0';
		*string_in = end;
	}
	else
		*string_in = NULL;
	return (begin);
}
