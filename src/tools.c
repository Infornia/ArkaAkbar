/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:35:25 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/31 23:42:26 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

void			tools_menu_init(t_ark *a)
{
	a->menu = malloc(sizeof(t_menu));
	a->menu->is_open = 0;
	a->menu->current = MENU_RESUME;
}

void				tools_gl_antialiasing(void)
{
	glfwWindowHint(GLFW_SAMPLES, 8);
	glEnable(GL_MULTISAMPLE);
}

void			tools_game_init(t_ark *a)
{
	a->j1 = malloc(sizeof(t_player));
	a->j2 = malloc(sizeof(t_player));
	a->j1->name = ft_strdup("PLAYER 1");
	a->j2->name = ft_strdup("PLAYER 2");
	a->j1->score = 0;
	a->j2->score = 0;
	a->ball = ball_create();
	a->chrono = (t_chrono *)malloc(sizeof(t_chrono));
	a->chrono->start = time(0);
}
void				tools_gl_exit(t_ark *a)
{
	glfwDestroyWindow(a->window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

GLFWwindow			*tools_gl_init(t_ark *a)
{
	glfwSetErrorCallback(callback_error);
	if (!glfwInit())
		ft_error("Cannot initialize GLFW.");
	a->window = glfwCreateWindow(WKW_WINW, WKW_WINH,
			ARCANOID_TITLE, NULL, NULL);
	if (!a->window)
	{
		glfwTerminate();
		ft_error_num(EXIT_FAILURE, "Cannot create window.");
	}
	glfwMakeContextCurrent(a->window);
	tools_gl_antialiasing();
	glfwSwapInterval(1);
	glfwSetInputMode(a->window, GLFW_STICKY_KEYS, 1);
	glfwSetKeyCallback(a->window, callback_key);
	tools_menu_init(a);
	tools_game_init(a);
	return (a->window);
}

void				tools_gl_setortho(t_ark *a)
{
	a->ratio = a->w / (float)a->h;
	glViewport(0, 0, a->w, a->h);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-a->ratio, a->ratio, -2.f, 2.f, 2.f, -2.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void				tools_gl_loop(t_ark *a)
{
	glfwGetFramebufferSize(a->window, &(a->w), &(a->h));
	tools_gl_setortho(a);
	game_update(a);
	if (a->menu->is_open)
	{
		menu_background(a);
		menu_buttons(a);
		key_menu_nav_up(a);
		key_menu_nav_down(a);
	}
	else
	{
		draw_game(a);
		chrono_display(a);
	}

	key_pause(a);
	glfwSwapBuffers(a->window);
	glfwPollEvents();
}
