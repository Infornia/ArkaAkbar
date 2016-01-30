/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:50:52 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 19:50:56 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_size(int nb)
{
	int		i;

	i = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		nb /= 10;
		++i;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*ret;
	int		sign;

	if (n == -2147483648)
		return (ft_strtrim("-2147483648"));
	i = ft_size(n);
	sign = 1;
	if (n < 0)
	{
		++sign;
		n *= -1;
	}
	ret = ft_strnew(i + sign - 1);
	if (!ret || !i)
		return (NULL);
	while (i)
	{
		--i;
		ret[i - 1 + sign] = n % 10 + '0';
		n /= 10;
		if (!i && sign > 1)
			ret[i] = '-';
	}
	return (ret);
}
