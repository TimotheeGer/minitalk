# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 15:04:29 by tigerber          #+#    #+#              #
#    Updated: 2021/10/18 16:37:24 by tigerber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client

SRCS1 =	server/server.c \
		utils_minitalk.c \
		utils_minitalk_two.c

SRCS2 = client/client.c \
		utils_minitalk.c \
		utils_minitalk_two.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./include/

HEADER = -I ./includes/

OBJS1 = $(SERVER:%.c=%.o)
OBJS2 = $(CLIENT:%.c=%.o)

$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1) $(LIBS)

$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2) $(LIBS)

all: $(NAME1) $(NAME2)

%.o%.c:
	$(CC) -c $(CFLAGS) -I $(HEADER) $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS1) $(OBJS2) $(OBJS_BONUS)

fclean: clean
	rm -f $(OBJS1) $(OBJS2)

re: fclean all

.PHONY: all clean fclean re