/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:53:20 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 19:53:23 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cp;
	unsigned char	*s2_cp;

	s1_cp = (unsigned char *)s1;
	s2_cp = (unsigned char *)s2;
	while (n && (*s1_cp == *s2_cp))
	{
		++s1_cp;
		++s2_cp;
		--n;
	}
	if (!n)
		return (0);
	return ((int)*s1_cp - (int)*s2_cp);
}
