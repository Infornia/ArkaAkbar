/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:58:34 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 19:58:34 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	int			i;
	size_t		len;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL && s1 != NULL)
		return (ft_strdup(s1));
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	s = ft_strnew(len + 1);
	if (s == NULL || (s1 == NULL && s2 == NULL))
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		s[i] = *s2++;
		i++;
	}
	s[i] = '\0';
	return (s);
}
