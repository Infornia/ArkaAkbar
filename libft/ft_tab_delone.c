/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_delone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 06:08:33 by cdivry            #+#    #+#             */
/*   Updated: 2015/10/22 01:44:37 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_tab_delone_loop(char ***tab, char *elem, int *ok, char ***ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ft_tab_count(*tab))
	{
		if (ft_strcmp((char *)(*tab)[i], (char *)elem))
		{
			(*ret)[j] = ft_strdup((char *)(*tab)[i]);
			j++;
		}
		else
			(*ok)++;
		(*ret)[j] = NULL;
		i++;
	}
}

int			ft_tab_delone(char ***tab, char *elem)
{
	char	**ret;
	int		ok;

	ok = 0;
	if (*tab)
	{
		ret = NULL;
		ret = (char **)malloc(sizeof(char *) * (ft_tab_count(*tab) + 2));
		ft_tab_delone_loop(tab, elem, &ok, &ret);
		*tab = ret;
	}
	return (ok);
}
