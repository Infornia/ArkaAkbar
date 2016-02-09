/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highscore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:00:52 by cdivry            #+#    #+#             */
/*   Updated: 2016/02/01 20:12:25 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		highscore_save(t_ark *a, char *player, char *score)
{
	int	fd;

	(void)a;
	fd = open("arkanoid_scores.txt", O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
	if (fd <= 0)
	{
		ft_error("Le highscore ne peut pas être sauvegardé\n"
			"(arkanoid_scores.txt)");
	}
	ft_putstr_fd(player, fd);
	ft_putstr_fd(" = ", fd);
	ft_putstr_fd(score, fd);
	ft_putstr_fd(" pts.\n", fd);
	close(fd);
}

void		highscore_j1(t_ark *a)
{
	highscore_save(a, a->j1->name, ft_itoa(a->j1->score));
}

void		highscore_j2(t_ark *a)
{
	highscore_save(a, a->j2->name, ft_itoa(a->j2->score));
}

void		highscore_j1_display(t_ark *a)
{
	text_display_white(-1.f, 1.1f, "J1 :");
	text_display_white(-0.9f, 1.1f, a->j1->name);
	text_display_white(-1.f, 1.f, "Score :");
	text_display_white(-0.8f, 1.f, ft_itoa(a->j1->score));
}

void		highscore_j2_display(t_ark *a)
{
	text_display_white(0.6f, 1.1f, "J2 :");
	text_display_white(0.7f, 1.1f, a->j2->name);
	text_display_white(0.6f, 1.f, "Score :");
	text_display_white(0.8f, 1.f, ft_itoa(a->j2->score));
}
