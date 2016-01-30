/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:59:57 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 19:59:57 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s2[i])
			s1[i] = s2[i];
		else if (s1[i])
		{
			while (i < n)
			{
				s1[i] = '\0';
				++i;
			}
			return (s1);
		}
		++i;
	}
	return (s1);
}
