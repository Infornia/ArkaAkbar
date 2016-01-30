/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:59:19 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 19:59:20 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*ret;

	if (!s || !f)
		return (0);
	i = 0;
	ret = ft_strnew(ft_strlen(s));
	if (!ret)
		return (0);
	while (s[i])
	{
		ret[i] = f(s[i]);
		++i;
	}
	return (ret);
}
