/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:01:31 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/13 19:52:08 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// void    minitalk_client(pid_t pid, char *str)
// {
// 	int i = 0;

// 	if (kill(pid, SIGUSR2) == -1)
// 		exit(0);
// 	if (kill(pid, SIGUSR1) == -1)
// 		exit(0);
	
// }


void	convert_bits(pid_t pid, char c)
{
	// t     		i       			m 
	// 116   		105					109
	// 1110100		1101001				1101101
	int i = 6;

	while (i >= 0)
	{
		if ((c & (1 << i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(1000);
	}
}

int main(int ac, char **av)
{
	pid_t pid = atoi(av[1]);
	int i = 0;

	while (av[2][i])
	{
		convert_bits(pid, av[2][i]);
		i++;
	}
	// char *str = "01101001";
	// int i = 0;
	
	// while (str[i])
	// {
	// 	if (str[i] == '0') {
	// 		kill(pid, SIGUSR1);
	// 	}
	// 	if ( str[i] == '1')
	// 		kill(pid, SIGUSR2);
	// 	i++;	
	// 	usleep(800);
	// }
	// if (nb == 0)
	// 	kill(pid, SIGUSR1);
	// if (nb == 1)
	// 	kill(pid, SIGUSR2);
	// minitalk_client(atoi(av[1]), av[2]);
}

//malloc et realoc 