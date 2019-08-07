# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 19:30:49 by jtaylor           #+#    #+#              #
#    Updated: 2019/08/07 14:31:25 by jtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror -I ./libft/includes

DEBUG_FLAG = -g3

SRC =	ft_minishell_exec.c \
		ft_minishell_parse_env.c \
		ft_minishell_prompt.c \
		ft_minishell_signal.c \
		ft_minishell_exit.c \
		ft_minishell_env.c \
		ft_minishell_unsetenv.c \
		ft_minishell_builtin_env.c \
		ft_minishell_cd.c \
		minishell_main.c

.PHONY = all clean fclean re

all : $(NAME)

$(NAME) :
	@make -C ./libft
	@echo "\tBuilding $(NAME) executable\n"
	@gcc $(FLAGS) $(SRC) -I ./includes ./libft/libft.a ./libft/ft_printf/libftprintf.a -o $(NAME)

debug :
	@make debug -C ./libft
	@echo "\tBuilding $(NAME) debug executable\n"
	@gcc $(FLAGS) $(SRC) $(DEBUG_FLAG) -I ./includes ./libft/libft.a ./libft/ft_printf/libftprintf.a -o $(NAME)

clean :
	@make -C libft clean

fclean : clean
	@echo "\tRemoving minishell Executable\n"
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@make -C libft fclean

re : fclean all

r :
	rm $(NAME);
	make all
