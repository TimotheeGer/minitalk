/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:04:55 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/18 12:30:06 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BUFF_MAX 7

typedef struct s_minitalk
{
	char	buff[BUFF_MAX];
	int		x;
}				t_minitalk;

int		ft_send_signal(pid_t pid, char c);

void	ft_add_to_buff(t_minitalk *d, char c);

void	ft_empty_buff(t_minitalk *d);

void	ft_put_bin_to_char(char *str);

void	*ft_memset(void *s, int c, size_t n);

int		ft_strlen(char *str);

char	*ft_itoa(int n);

int		countnum(int n);

int		ft_atoi(const char *nptr);

void	ft_putnbr(long nb);

int		ft_error(char *str);

#endif
