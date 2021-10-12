/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:01:31 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/12 17:20:19 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void    minitalk_client(pid_t pid, char *str)
{
    int i = 0;

    if (kill(pid, SIGUSR2) == -1)
        exit(0);
    if (kill(pid, SIGUSR1) == -1)
        exit(0);
    
}

int main(int ac, char **av)
{
    minitalk_client(atoi(av[1]), av[2]);
}

//malloc et realoc 