/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 02:22:17 by cdivry            #+#    #+#             */
/*   Updated: 2014/05/04 08:41:55 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static t_read		*ft_freeread(t_read *red, t_read *prev, t_read **start)
{
	if (!prev)
		*start = red->next;
	else
		prev->next = red->next;
	free(red->read);
	free(red);
	if (!prev)
		return (*start);
	else
		return (prev->next);
}

static t_read		*ft_newread(int fd)
{
	t_read			*red;
	char			*tmp;
	int				ret;

	if (!(red = (t_read *)malloc(sizeof(t_read))))
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
	{
		free(red);
		return (NULL);
	}
	if ((ret = read(fd, tmp, BUFF_SIZE)) < 0)
	{
		free(red);
		free(tmp);
		return (NULL);
	}
	tmp[ret] = 0;
	red->read = (char *)tmp;
	red->fd = fd;
	red->size = ret;
	red->next = NULL;
	red->index = 0;
	return (red);
}

static int			ft_print(int n, t_read **tab, t_read **s, char **l)
{
	char			*tmpstr;
	int				index;

	if (!tab[0])
		return (-1);
	index = (tab[0])->index;
	if (n == -1 || !(tmpstr = (char *)malloc(sizeof(char) * (n + 1))))
		return (-1);
	*l = tmpstr;
	while (n--)
	{
		*tmpstr++ = (tab[0])->read[index++];
		if (index == (tab[0])->size)
		{
			tab[0] = ft_freeread(tab[0], tab[1], s);
			index = 0;
		}
	}
	*tmpstr = 0;
	if (!tab[0] || (index == tab[0]->size && tab[0]->size < BUFF_SIZE))
		return (0);
	tab[0]->index = index + 1;
	if (tab[0]->index == tab[0]->size)
		tab[0] = ft_freeread(tab[0], tab[1], s);
	return (1);
}

static int			ft_findendl(int fd, t_read *red)
{
	int				index;
	int				size;
	t_read			*tmplst;

	size = 0;
	index = red->index;
	while (red->read[index] != '\n' && index < red->size)
	{
		index++;
		size++;
		if (index == red->size && red->size == BUFF_SIZE)
		{
			if (!(tmplst = ft_newread(fd)))
				return (-1);
			tmplst->next = red->next;
			red->next = tmplst;
			red = tmplst;
			index = 0;
		}
	}
	return (size);
}

int					ft_getnextline(int fd, char **line)
{
	static t_read	*start = NULL;
	t_read			*red;
	t_read			*prevtmp;
	t_read			*tab[2];

	if (fd < 0)
		return (-1);
	prevtmp = NULL;
	if (!start)
		start = ft_newread(fd);
	red = start;
	while (red->fd != fd)
	{
		if (!(red->next))
			red->next = ft_newread(fd);
		prevtmp = red;
		red = red->next;
	}
	if (!red || !start)
		return (-1);
	tab[0] = red;
	tab[1] = prevtmp;
	return (ft_print(ft_findendl(fd, red), tab, &start, line));
}
