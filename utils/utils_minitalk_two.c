/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minitalk_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:13:57 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/20 14:52:28 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

void	ft_putnbr(long nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb = nb + (int) '0';
		write(1, &nb, 1);
	}
}

void	ft_put_buff_print(t_minitalk *d, char c)
{
	if (c == '\0')
	{
		write (1, d->buf, d->i);
		write (1, "\n", 1);
		d->i = 0;
	}
	if (c != '\0')
	{
		d->buf[d->i] = c;
		d->i++;
	}
	if (d->i == BUFF_M)
	{
		write (1, d->buf, d->i);
		write (1, "\n", 1);
		d->i = 0;
	}
}
