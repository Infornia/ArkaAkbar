/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 05:36:14 by cdivry            #+#    #+#             */
/*   Updated: 2015/10/22 01:23:16 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_tab_add_exec(char ***tab, char *elem)
{
	char	**ret;
	int		i;
	int		count;

	ret = NULL;
	count = ft_tab_count((char **)*tab);
	ret = (char **)malloc(sizeof(char *) * (count + 2));
	if (ret)
	{
		i = 0;
		while (i < count)
		{
			ret[i] = ft_strdup((*tab)[i]);
			i++;
		}
		ret[i] = ft_strdup(elem);
		ret[i + 1] = NULL;
		free(*tab);
		*tab = ret;
	}
}

void		ft_tab_add(char ***tab, char *elem)
{
	if (!(*tab))
	{
		*tab = (char **)malloc(sizeof(char *) * 2);
		(*tab)[0] = ft_strdup(elem);
		(*tab)[1] = NULL;
	}
	else
		ft_tab_add_exec(tab, elem);
}
