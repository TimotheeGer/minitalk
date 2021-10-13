/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:01:04 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/13 19:49:39 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

tmstruct mt;

void    re_convert(char *str);

void    empty_buff(tmstruct *mt)
{
    re_convert(mt->buff);
    // write(1, &mt->buff, mt->x);
    mt->x = 0;
}

void    add_to_buff(tmstruct *mt, char c)
{
    mt->buff[mt->x] = c;
    mt->x++;
    if (mt->x == BUFF_MAX)
        empty_buff(mt);
}

void    server(int sign)
{ 
    if (sign == SIGUSR1)
       add_to_buff(&mt, '1');
    else if (sign == SIGUSR2)
        add_to_buff(&mt, '0');
}

int val(char c)
{
    if (c >= '0' && c <= '9') //is digit
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}


void    re_convert(char *str)
{
    int bin = atoi(str);
    int binary = bin;
    int res = 0;
    int decimal = 0;
    int base = 1;
    char c = 0;
    while (bin > 0)
    {
        res = bin % 10;
        decimal = decimal + res * base;
        bin = bin / 10;
        base = base *2; 
    }
    c = (char)decimal;
    write(1, &c, 1);
    // printf("decimal = %c\n", (char)decimal);
}

int main(int ac, char **av)
{  
    int pid = getpid();
    tmstruct mt;
    
    memset(&mt, 0, sizeof(tmstruct));
    printf("PID = %d\n", pid);
    printf("======1=======\n");
    signal(SIGUSR1, server);
    signal(SIGUSR2, server);
    signal(SIGWINCH, SIG_IGN);
    write(1, "\n", 1);
    while (1)
    {
        sleep(1000);
    }
    return (0);
}


