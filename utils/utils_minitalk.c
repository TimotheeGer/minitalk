/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minitalk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:27:10 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/20 14:50:22 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < (int)n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
	{
		i++;
	}
	if (nptr[i] == '-')
	{
		neg = -1;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = res + (nptr[i] - 48);
		i++;
	}
	return (res * neg);
}

int	countnum(int n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long n)
{
	int		size;
	char	*str;

	size = countnum(n);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (size-- && n > 0)
	{
		str[size] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
