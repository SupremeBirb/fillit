# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelee <lelee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/11 09:31:17 by jfelty            #+#    #+#              #
#    Updated: 2019/08/19 18:10:03 by lelee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g
SRC = srcs/tetrovalid.c \
			srcs/populate.c \
			srcs/o_r_c.c \
			srcs/grid_memory.c \
			srcs/fillit.c \
			srcs/placencheck.c
			

all: $(NAME)

$(NAME): lib out

lib:
	@make -C libft
	@cp libft/libft.a .
	@echo "Library Copy Complete"
#uses make command in library

out:
	@$(CC) $(CFLAGS) $(SRC) libft.a -o fillit
	@$(CC) $(CFLAGS) $(SRC) -fsanitize=address libft.a -o fillit2
	@echo "Fillit Generation Complete"

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a
	@make -C libft/ fclean

re: fclean all

.PHONY: lib out clean all fclean re fillit