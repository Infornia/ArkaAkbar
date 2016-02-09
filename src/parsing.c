/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 23:57:44 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/31 04:41:17 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <stdio.h>

static void add_block(t_block **b, int x, int y, int life)
{
	t_block	*new;
	t_block	*tmp;

	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	new = malloc(sizeof(t_block));
	new->next = NULL;
	tmp->next = new;
	tmp->next->prev = tmp;

	new->life = life;
	new->pos.x = x;
	new->pos.y = y;
}

static void	fill_blocks(t_block **b, char **t, int y)
{
	int		x;

	x = -1;
	while (t[++x])
		add_block(b, x, y, ft_atoi(t[x]));
}

static t_block	*new_block(void)
{
	t_block *new;

	new = malloc(sizeof(t_block));
	new->next = NULL;
	new->prev = NULL;
	new->life = -1;
	new->pos.x = 0;
	new->pos.y = 0;
	return (new);
}

void	get_level(t_ark *a, const char *file)
{
	int		fd;
	char	*line;
	int		i;
	t_block *del;

	i = 0;
	line = NULL;
	a->map = new_block();
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error_num(errno, "Open failed");
	while ((ft_getnextline(fd, &line)) > 0)
	{
		if (ft_strlen(line) != 43)
			ft_error("MAN you file is shit as hell !");
		fill_blocks(&a->map, ft_strsplit(line, ' '), i);
		i++;
	}
	del = a->map;
	a->map = a->map->next;
	del->next = NULL;
	free(del);
	close(fd);
}
