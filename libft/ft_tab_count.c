/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 05:59:54 by cdivry            #+#    #+#             */
/*   Updated: 2015/10/22 01:36:43 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_count(char **tab)
{
	int	i;

	if (!(tab))
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}