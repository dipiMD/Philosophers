# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drakan <drakan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 11:05:49 by drakan            #+#    #+#              #
#    Updated: 2022/03/12 20:15:21 by drakan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS 		=	utils.c \
				time_opeation.c \
				parsing.c \
				init.c \
				free.c \
				main.c

HEADER		=	philosophers.h

OBJ=$(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
		$(CC) $(OBJ) -o $(NAME)

all:
	$(MAKE) $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all