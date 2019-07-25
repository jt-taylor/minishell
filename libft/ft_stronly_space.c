/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stronly_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:51:58 by jtaylor           #+#    #+#             */
/*   Updated: 2019/07/24 16:19:24 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stronly_space(char *str)
{
	int		i = 0;

	while (str[i])
	{
		if (str[i] > 32)
			break;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	return (1);
}
