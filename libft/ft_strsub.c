/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 20:01:52 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 20:01:52 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (0);
	ret = ft_strnew(len);
	if (!ret)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s[start];
		++i;
		++start;
	}
	return (ret);
}
