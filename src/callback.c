/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:39:52 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/31 23:41:01 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>

void	callback_error(int error, const char* description)
{
	ft_error_num(error, description);
}

void	callback_key(GLFWwindow *window, int key,
		int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	(void)action;
	(void)key;
	(void)window;

	key_exit(window, key, action);
}
