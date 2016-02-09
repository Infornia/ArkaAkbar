/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fuck_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:54:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/31 23:33:07 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "arkanoid.h"
#include <glfw/glfw3.h>
#include <SOIL.h>
#include <libft.h>
#include <stdlib.h>

void		draw_ball(t_ark *a, t_ball *ball)
{
	double		block_width;
	double		block_height;
	double		posx;
	double		posy;

	block_width = a->w / 11000.f / 1.7;
	block_height = block_width;
	posx = ball->x * block_width - 1.0f;
	posy = -ball->y * block_height + 0.9f;

	glBegin(GL_QUADS);
	glColor3f(8.0f, 6.0f, 4.0f);
	glVertex2f(posx, posy);
	glVertex2f(posx + block_width, posy);
	glVertex2f(posx + block_width, posy + block_height);
	glVertex2f(posx, posy + block_height);
	glEnd();
}
