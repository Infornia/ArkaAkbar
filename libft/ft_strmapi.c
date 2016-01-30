/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 20:03:22 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 20:03:23 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (!s || !f)
		return (0);
	i = 0;
	ret = ft_strnew(ft_strlen(s));
	if (!ret)
		return (0);
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		++i;
	}
	return (ret);
}
