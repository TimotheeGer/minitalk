/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:01:04 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/19 17:14:01 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_minitalk	d;

void	ft_empty_buff(t_minitalk *d)
{
	ft_put_bin_to_char(d->buff);
	d->x = 0;
}

void	ft_add_to_buff(t_minitalk *d, char c)
{
	d->buff[d->x] = c;
	d->x++;
	if (d->x == BUFF_MAX)
		ft_empty_buff(d);
}

void	server(int sign)
{
	if (sign == SIGUSR1)
		ft_add_to_buff(&d, '1');
	else if (sign == SIGUSR2)
		ft_add_to_buff(&d, '0');
}

void	ft_put_bin_to_char(char *str)
{
	int		bin;
	int		res;
	int		decimal;
	int		base;
	char	c;

	bin = ft_atoi(str);
	res = 0;
	decimal = 0;
	base = 1;
	c = 0;
	while (bin > 0)
	{
		res = bin % 10;
		decimal = decimal + res * base;
		bin = bin / 10;
		base = base * 2;
	}
	c = (char)decimal;
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		write(1, "PID = ", 7);
		ft_putnbr(getpid());
		write(1, "\n", 1);
		ft_memset(&d, 0, sizeof(t_minitalk));
		if (signal(SIGUSR1, server))
			return (ft_error("Error SIGUSR1.\n"));
		if (signal(SIGUSR2, server))
			return (ft_error("Error SIGUSR2.\n"));
		while (1)
			sleep(1000);
	}
	else
		return (ft_error("Error to much Argument.\n"));
	return (0);
}
