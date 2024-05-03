# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 13:25:40 by dangonz3          #+#    #+#              #
#    Updated: 2024/05/03 10:55:02 by dangonz3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c auxiliars.c printer.c

INCLUDE = ft_printf.h

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

# ************************************ #

OBJS := $(SRC:%.c=%.o)

%.o: %.c $(INCLUDE)
		$(CC) $(CCFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re