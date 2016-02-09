/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:00:52 by cdivry            #+#    #+#             */
/*   Updated: 2016/01/31 22:33:09 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int		time_spent(t_chrono *c)
{
	int	seconds;

	c->end = time(0);
	seconds = 0;
	seconds = (int)(c->end - c->start);
	return (seconds);
}

void	chrono_string(t_ark *ark, int hrs, int min, int sec)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	str[0] = 0;
	(void)ark;
	str = ft_strjoin("[ chrono : ", ft_itoa(hrs));
	str = ft_strjoin(str, "h ");
	str = ft_strjoin(str, ft_itoa(min));
	str = ft_strjoin(str, "min ");
	str = ft_strjoin(str, ft_itoa(sec));
	str = ft_strjoin(str, "sec ]");
	text_display_white(-1.f, -1.f, str);
	free(str);
}

void	chrono_display(t_ark *a)
{
	int	hrs;
	int	min;
	int	sec;
	int	now;

	now = time_spent(a->chrono);
	hrs = (now / 3600);
	min = ((now % 3600) / 60);
	sec = (now % 60);
	chrono_string(a, hrs, min, sec);
}
