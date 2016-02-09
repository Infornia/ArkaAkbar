/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cdivry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:38:03 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/31 23:38:21 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void	print_usage(void)
{
	ft_putstr("\033[35m\n\t *****Welcome to Arkanoid*****\n\n\033[0m");
	ft_putstr("\033[32m\tusage: ./arkanoid levels/[Map]\n\n\033[0m");
	ft_putstr("\033[33m\t---------Commands---------\n");
	ft_putstr("\tMoves:\t\t\tArrows\n\n\033[0m");
	ft_putstr("\033[36m\tPause:\t\t\tp\n\033[0m");
	ft_putstr("\033[31m\tExit:\t\t\tesc\n\n\033[0m");
}

int				main(int ac, char **av)
{
	t_ark		ark;

	if (ac == 2)
	{
		get_level(&ark, av[1]);
		ark.window = NULL;
		ark.window = tools_gl_init(&ark);
		while (!glfwWindowShouldClose(ark.window))
			tools_gl_loop(&ark);
		tools_gl_exit(&ark);
	}
	else
		print_usage();
	return (0);
}
