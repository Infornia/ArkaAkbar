/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:40:36 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/31 23:40:41 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "arkanoid.h"
#include <GLFW/glfw3.h>

void	key_exit(GLFWwindow *window, int key, int action)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}


void	key_pause(t_ark *a)
{
	static int flag = 0;

	if (glfwGetKey(a->window, GLFW_KEY_P) == GLFW_RELEASE)
		flag = 0;
	if (glfwGetKey(a->window, GLFW_KEY_P) == GLFW_PRESS && !flag)
	{
		flag = 1;
		if (a->menu->is_open)
			a->menu->is_open = 0;
		else
			a->menu->is_open = 1;
	}
}

void	key_menu_nav_up(t_ark *a)
{
	static int flag = 0;

	if (a->menu->is_open)
	{
		if (glfwGetKey(a->window, GLFW_KEY_UP) == GLFW_RELEASE)
			flag = 0;
		if (glfwGetKey(a->window, GLFW_KEY_UP) == GLFW_PRESS && !flag)
		{
			flag = 1;
			if (a->menu->current == MENU_RESUME)
				a->menu->current = MENU_OPTION;
			else if (a->menu->current == MENU_OPTION)
				a->menu->current = MENU_QUIT;
			else if (a->menu->current == MENU_QUIT)
				a->menu->current = MENU_RESUME;
		}

	}
}

void	key_menu_nav_down(t_ark *a)
{
	static int flag = 0;

	if (a->menu->is_open)
	{
		if (glfwGetKey(a->window, GLFW_KEY_DOWN) == GLFW_RELEASE)
			flag = 0;
		if (glfwGetKey(a->window, GLFW_KEY_DOWN) == GLFW_PRESS && !flag)
		{
			flag = 1;
			if (a->menu->current == MENU_RESUME)
				a->menu->current = MENU_QUIT;
			else if (a->menu->current == MENU_QUIT)
				a->menu->current = MENU_OPTION;
			else if (a->menu->current == MENU_OPTION)
				a->menu->current = MENU_RESUME;
		}
	}
}

