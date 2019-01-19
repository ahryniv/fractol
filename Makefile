# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 20:46:31 by ahryniv           #+#    #+#              #
#    Updated: 2017/03/28 20:57:18 by ahryniv          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WWW = -Wall -Wextra -Werror

NAME = fractol

LIBFT = ./libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft/

$(NAME): 
	gcc *.c libft/libft.a -Werror -Wextra -Wall -lmlx -lXext -lX11 -L libmlx/ -I libmlx/ -pthread

clean:
	make clean -C./libft/
	rm -f main.o
 
fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all
