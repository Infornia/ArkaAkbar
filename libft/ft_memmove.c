/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:54:04 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 19:54:05 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*buf;

	buf = (unsigned char *)malloc(sizeof(unsigned char) * n);
	if (!buf)
		return (0);
	ft_memcpy(buf, s2, n);
	ft_memcpy(s1, buf, n);
	free(buf);
	return (s1);
}
