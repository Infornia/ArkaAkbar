/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 20:01:08 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 20:01:08 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	while (i)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		--i;
	}
	if (s[i] == (char)c)
		return ((char *)s);
	return (0);
}
