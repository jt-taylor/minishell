# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 19:30:49 by jtaylor           #+#    #+#              #
#    Updated: 2019/07/10 09:11:03 by jtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror -I ./libft/includes

DEBUG_FLAG = -g

SRC = 

.PHONY = all clean fclean re

all : $(NAME)

$(NAME) :
	@make -C ./libft
	@echo "\tBuilding $(NAME) executable\n"
	@gcc $(FLAGS) $(SRC) -I ./includes ./libft/libft.a ./libft/ft_printf/libftprintf.a -o $(NAME)

debug :
	@make -C ./libft
	@echo "\tBuilding $(NAME) debug executable\n"
	@gcc $(FLAGS) $(SRC) $(DEBUG_FLAG) -I ./includes ./libft/libft.a ./libft/ft_printf/libftprintf.a -o $(NAME)

clean :
	@echo "\tRemoving files\n"
	@make -C libft clean

fclean : clean
	@echo "\tRemoving Executable\n"
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@make -C libft fclean

re : fclean all
