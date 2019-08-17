# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelee <lelee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/11 09:31:17 by jfelty            #+#    #+#              #
#    Updated: 2019/08/17 02:44:18 by lelee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = @gcc

CFLAGS = -Wall -Wextra -Werror
SRC = tetrovalid.c \
			populate.c \
			o_r_c.c \
			grid_memory.c
			
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib out

lib:
	@make -C libft
	@cp libft/libft.a .
	@echo "Library Copy Complete"
#uses make command in library

out:
	@$(CC) $(CFLAGS) $(SRC) libft.a -o fillit 
	@echo "Fillit Generation Complete"

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: lib out clean all fclean re