/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 20:00:23 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 20:00:23 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	if (!size)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	while (size)
	{
		ret[size] = '\0';
		--size;
	}
	ret[size] = '\0';
	return (ret);
}
