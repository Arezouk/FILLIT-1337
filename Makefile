# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arezouk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 23:11:34 by arezouk           #+#    #+#              #
#    Updated: 2018/12/01 19:17:39 by arezouk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = source/*.c functions/*.c

INCLUDE = include/

$(NAME): $(LIB)
	gcc -o $(NAME) -Wall -Wextra -Werror $(SRCS) -I $(INCLUDE)

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
