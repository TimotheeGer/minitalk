 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 15:04:29 by tigerber          #+#    #+#              #
#    Updated: 2021/10/19 00:54:40 by tigerber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -I ./include/
EXEC_C 	= prog_client
EXEC_S 	= prog_server

SRC_C =	./client/client.c \
		./utils/utils_minitalk.c \
		./utils/utils_minitalk_two.c

SRC_S =	./server/server.c \
		./utils/utils_minitalk.c \
		./utils/utils_minitalk_two.c

OBJ_C =	$(SRC_C:.c=.o)
OBJ_S =	$(SRC_S:.c=.o)

all : $(EXEC_C) $(EXEC_S) 

$(EXEC_C) : $(OBJ_C)
	@$(CC) $(CFLAGS) -o $(EXEC_C) $(OBJ_C)
	@printf "\x1b[32m--------------------------------------\n" 
	@printf "\x1b[32m./$@ successfully build 💻 ✅\e[0m\n" 
	@printf "\x1b[32m--------------------------------------\n" 

$(EXEC_S) : $(OBJ_S)
	@$(CC) $(CFLAGS) -o $(EXEC_S) $(OBJ_S)
	@printf "\e[38;5;46m./$@ successfully build 🖥  ✅\e[0m\n"
	@printf "\e[38;5;46m--------------------------------------\n"

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	
clean :
	@rm -rf ./client/*.o
	@rm -rf ./server/*.o
	@rm -rf ./utils/*.o
	@printf "\e[38;5;206m--------------------------------------\n"
	@printf "\e[38;5;206mAll.o files deleted              🗑  ❌\e[0m\n"
	@printf "\e[38;5;206m--------------------------------------\n"

fclean : clean
	@rm -rf prog_client
	@rm -rf prog_server
	@printf "\e[38;5;200mProg deleted                     🗑  ❌\e[0m\n"
	@printf "\e[38;5;200m--------------------------------------\n"

re : fclean all