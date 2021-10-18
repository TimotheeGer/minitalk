/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minitalk_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:13:57 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/18 12:24:41 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

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
