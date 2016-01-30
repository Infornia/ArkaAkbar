/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:52:58 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 19:52:59 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	const char	*src;
	char		*dst;
	char		current;

	dst = s1;
	src = s2;
	while (n)
	{
		current = *src++;
		*dst++ = current;
		if (current == (char)c)
			return (dst);
		--n;
	}
	return (0);
}
