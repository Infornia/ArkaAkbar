/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:49:22 by cdivry            #+#    #+#             */
/*   Updated: 2016/01/24 00:05:41 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int					ft_atoi_overlimit(char *str)
{
	if (ft_strcmp(ft_itoa(ft_atoi(str)), str) == 0)
		return (0);
	return (1);
}

int					ft_atoi(const char *str)
{
	int				i;
	unsigned int	value;
	int				sign;

	i = 0;
	sign = 1;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || str[i] == '\n')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		value = (value * 10) + (str[i++] - 48);
	return (sign * (int)value);
}
