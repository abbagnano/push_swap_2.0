/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:01:42 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/25 18:01:44 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_strchr(char c, char *s1)
{
	int	x;

	x = 0;
	while (s1 && s1[x])
	{
		if (s1[x] == c)
			return (x);
		x++;
	}
	return (-1);
}

int	ft_strncmp(char *s1, char *s2, int len)
{
	while (s1 && s2 && *s1 && *s2 && *s1 == *s2 && --len)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (s1 && s2 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
