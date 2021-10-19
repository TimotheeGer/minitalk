/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minitalk_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:13:57 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/19 17:07:25 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

// int	ft_error_malloc(t_minitalk *d, char *str)
// {
// 	if (d->str == NULL)
// 	{
// 		ft_free_and_null(d);
// 		write(1, str, ft_strlen(str));
// 		exit (0);
// 	}
// 	else
// 		return (0);
// }

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

// void	ft_free_and_null(t_minitalk *d)
// {
// 	if (d->temp)
// 	{
// 		free(d->temp);
// 		d->temp = NULL;	
// 	}
// }

// void	ft_stock_char_and_put(t_minitalk *d, char c)
// {	
// 	(void)d;
// 		write(1, &c, 1);
// 	int i;

// 	i = 0;
// 	d->temp = d->str;
// 	if (c != '\0')
// 	{
// 		d->str = malloc(sizeof(char) * (ft_strlen(d->temp) + 2));
// 		ft_error_malloc(d, "Error Malloc.\n");
// 		while (i < ft_strlen(d->temp))
// 		{
// 			d->str[i] = d->temp[i];
// 			i++;
// 		}
// 		d->str[i] = c;
// 		d->str[i + 1] = '\0';
// 		if (d->temp)
// 		{
// 			free(d->temp);
// 			d->temp = NULL;		
// 		}
// 	}
// 	else if (c == '\0')
// 	{
// 		write(1, d->str, ft_strlen(d->str));
// 		write(1, "\n", 1);
// 		free(d->temp);
// 		d->temp = NULL;
// 		d->str = NULL;
// 	}
// }
