/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 18:15:04 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/31 23:40:22 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <glfw/glfw3.h>
#include <SOIL.h>
#include <libft.h>
#include <stdlib.h>

static void			draw_bar(t_ark *a, t_player *bar)
{
	double		block_width;
	double		block_height;
	double		posx;
	double		posy;

	bar->y = 21;
	block_width = a->w / 11000.f / 1.7;
	block_height = a->h / 11000.f;
	posx = bar->x * block_width - 1.0f;
	posy = -bar->y * block_height + 0.9f;

	glBegin(GL_QUADS);
	glColor3f(8.0f, 6.0f, 4.0f);
	glVertex2f(posx, posy);
	glVertex2f(posx + block_width, posy);
	glVertex2f(posx + block_width, posy + block_height);
	glVertex2f(posx, posy + block_height);
	glEnd();
}

static void		draw_block_border(t_vector *pos, float block_width,
		float block_height)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(pos->x, pos->y);
	glVertex2f(pos->x, pos->y + block_height);
	glVertex2f(pos->x, pos->y + block_height);
	glVertex2f(pos->x + block_width, pos->y + block_height);
	glVertex2f(pos->x + block_width, pos->y + block_height);
	glVertex2f(pos->x + block_width, pos->y);
	glVertex2f(pos->x + block_width, pos->y);
	glVertex2f(pos->x, pos->y);
	glEnd();
}

static void		draw_block(t_ark *a, t_block *block)
{
	float		block_width;
	float		block_height;
	t_vector	pos;
	float		color[4];

	block_width = a->w / 11000.f / 1.7;
	block_height = a->h / 11000.f;
	pos.x = block->pos.x * block_width - 1.0f;
	pos.y = -block->pos.y * block_height + 0.9f;
	if (block->life == 1)
		glColor3f(0.0f, 0.0f, 0.8f);
	else if (block->life == 2)
		glColor3f(0.0f, 0.8f, 0.0f);
	else if (block->life == 3)
		glColor3f(0.8f, 0.0f, 0.0f);
	else
		glColor3f(0.8f, 0.8f, 0.8f);
	glGetFloatv(GL_CURRENT_COLOR, color);
	glBegin(GL_QUADS);
	glVertex2f(pos.x, pos.y);
	glVertex2f(pos.x + block_width, pos.y);
	glColor3f(color[0] * 3, color[1] * 3, color[2] * 3);
	glVertex2f(pos.x + block_width, pos.y + block_height);
	glVertex2f(pos.x, pos.y + block_height), glEnd();
	draw_block_border(&pos, block_width, block_height);
}

static void		draw_blocks(t_ark *a)
{
	t_block *tmp;

	tmp = a->map;
	while (tmp)
	{
		if (tmp->life > 0)
			draw_block(a, tmp);
		tmp = tmp->next;
	}
}

void			draw_game(t_ark *a)
{
	draw_blocks(a);
	draw_bar(a, a->j1);
}
