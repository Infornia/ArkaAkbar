/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:52:44 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 19:52:45 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ret;
	size_t			i;

	i = 0;
	ret = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (!ret)
		return (NULL);
	while (i < size)
	{
		ret[i] = 0;
		++i;
	}
	return ((unsigned char *)ret);
}
