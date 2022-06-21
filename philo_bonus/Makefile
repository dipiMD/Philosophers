# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drakan <drakan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 11:05:49 by drakan            #+#    #+#              #
#    Updated: 2022/03/12 20:15:37 by drakan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_B		=	philo_bonus

SRCS_B		=	utils_bonus.c \
				time_opeation_bonus.c \
				parsing_bonus.c \
				init_bonus.c \
				free_bonus.c \
				main_bonus.c

HEADER_B	=	philosophers_bonus.h

OBJ_B=$(SRCS_B:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME_B): $(OBJ_B) $(HEADER_B)
		$(CC) $(OBJ_B) -o $(NAME_B)

all:
	$(MAKE) $(NAME_B)

bonus:
	$(MAKE) $(NAME_B)

clean:
	rm -f $(OBJ_B)

fclean: clean
	rm -f $(NAME_B)

re:
	make fclean
	make all