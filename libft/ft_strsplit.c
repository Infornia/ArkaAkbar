/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:15:55 by cdivry            #+#    #+#             */
/*   Updated: 2015/01/24 16:15:56 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	word_count(const char *s, char c)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			++j;
			while (s[i] != c)
			{
				if (!s[i])
					return (j);
				++i;
			}
		}
	}
	return (j);
}

static int	word_length(const char *s, int i, int j, char c)
{
	while (s[i] && s[i] != c)
	{
		++i;
		++j;
	}
	return (j);
}

static int	ft_free(char **tab)
{
	char	**tmp;

	if (tab)
	{
		tmp = tab;
		while (*tmp)
			free(*(tmp++));
		free(tab);
	}
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		k;
	int		word;

	if (!s)
		return (NULL);
	word = word_count(s, c);
	if (!(ret = (char**)malloc(sizeof(char*) * (word + 1))))
		return (NULL);
	i = 0;
	k = -1;
	ret[word] = 0;
	while (++k < word)
	{
		while (s[i] == c)
			++i;
		if (!(ret[k] = ft_strsub(s, i, word_length(s, i, 0, c)))
				&& ft_free(ret))
			return (NULL);
		while (s[i] && s[i] != c)
			++i;
	}
	ret[k] = NULL;
	return (ret);
}
