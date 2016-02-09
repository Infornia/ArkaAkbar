/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 21:10:50 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/31 23:33:08 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

t_ball	*ball_create(void)
{
	t_ball	*ball;

	ball = malloc(sizeof(t_ball));
	ball->balls_of_steel = 0;
	ball->x = 0;
	ball->y = -0.87f;
	ball->dx = 0;
	ball->dy = 1;
	ball->speed = 0;
	ball->next = NULL;
	return (ball);
}

static void	player_update(t_ark *a)
{
	glfwGetCursorPos(a->window, &a->j1->x, &a->j1->y);
	a->j1->x /= a->w / 21 + a->ratio;
	a->j1->x = a->j1->x <= 1 ? 1 : a->j1->x;
	a->j1->x = a->j1->x >= 20 ? 20 : a->j1->x;
	printf("%f, %f\n", a->j1->x, a->j1->y);
}

void	game_update(t_ark *a)
{
	player_update(a);
	chrono_display(a);
	highscore_j1_display(a);
	highscore_j2_display(a);
}
