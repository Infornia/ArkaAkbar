#include "arkanoid.h"

void	ft_error(const char *message)
{
	ft_putstr("\033[0;31mERROR : ");
	ft_putstr(message);
	ft_putstr("\033[0m\n");
	exit(0);
}

void	ft_error_num(int error, const char *message)
{
	ft_putstr("\033[0;31mERROR : ");
	ft_putstr(message);
	ft_putstr("\n(Error #");
	ft_putnbr(error);
	ft_putstr(")\033[0m\n");
	exit(0);
}
