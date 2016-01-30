/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 20:00:46 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 20:00:47 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sub_strn(const char *s1, const char *s2, size_t n, int i)
{
	while (*s2 == s1[i] && *s2 && i < (int)n)
	{
		++s2;
		++i;
	}
	if (!*s2)
		return (1);
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	if (*s2)
	{
		while (s1[i] && i < (int)n)
		{
			if (s1[i] == *s2)
			{
				if (ft_sub_strn(s1, s2, n, i))
					return ((char *)&s1[i]);
			}
			i++;
		}
		return (0);
	}
	return ((char *)s1);
}
