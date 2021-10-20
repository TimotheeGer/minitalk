/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:01:31 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/20 14:35:05 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_send_signal(pid_t pid, char c)
{
	int	i;

	i = 6;
	while (i >= 0)
	{
		if ((c & (1 << i)))
		{
			if (kill(pid, SIGUSR1) == -1)
				return (ft_error("Error PID.\n"));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (ft_error("Error PID.\n"));
		}
		i--;
		usleep(400);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac == 1)
		return (ft_error("Error missing PID & Argument.\n"));
	if (ac == 2)
		return (ft_error("Error missing Argument.\n"));
	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			if (!ft_send_signal(pid, av[2][i]))
				return (0);
			i++;
		}
		if (!ft_send_signal(pid, '\0'))
			return (0);
	}
	if (ac < 3)
		return (ft_error("Error to much Argumment.\n"));
	return (0);
}
