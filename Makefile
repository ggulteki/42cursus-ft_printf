# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggulteki <ggulteki@student.42istanbul.com. +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 20:46:56 by ggulteki          #+#    #+#              #
#    Updated: 2023/03/24 17:37:11 by ggulteki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAMEL = ./Libft/libft.a

FLAG = -Wall -Wextra -Werror

SRC  =	ft_printf.c \
		ft_printf_util.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C ./Libft
	cp Libft/libft.a $(NAME)
	ar rcs $@ $(OBJ)

.c.o:
	gcc $(FLAG) -c $< -o $(<:.c=.o)

clean:
	@rm -f *.o *a.out
	@make clean -C ./Libft

fclean:
	@rm -f *.o *a.out
	@rm -f $(NAME)
	@make fclean -C ./Libft

re: fclean all

.PHONY: all clean fclean re
