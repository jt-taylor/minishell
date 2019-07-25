# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 19:30:49 by jtaylor           #+#    #+#              #
#    Updated: 2019/07/24 13:01:31 by jtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror -I ./libft/includes

DEBUG_FLAG = -g3

SRC =	ft_minishell_exec.c \
		ft_minishell_find_executable.c \
		ft_minishell_loop.c \
		ft_minishell_parse_env.c \
		ft_minishell_prompt.c \
		ft_minishell_signal.c \
		ft_shell_process_input.c \
		minishell_main.c

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

r :
	rm $(NAME);
	make all
