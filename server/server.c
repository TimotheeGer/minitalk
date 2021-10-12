/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:01:04 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/12 17:18:45 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void    server()
{
    int pid = getpid();
    printf("PID = %d\n", pid);
    
}

void    server2()
{
    printf("ok\n");
    
}

int main(int ac, char **av)
{  
    server();   
    printf("signal Sigusr2 = %d\n", (int)signal(SIGUSR2, server));
    printf("signal Sigusr1 = %d\n", (int)signal(SIGUSR1, server2));
    sleep(1000);
}
