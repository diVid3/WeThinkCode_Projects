# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egenis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 11:37:42 by egenis            #+#    #+#              #
#    Updated: 2018/08/20 13:23:28 by egenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW = \033[0;33m

RESET = \033[0m

NAME = lem-in

CC = clang

FLAGS = -Wall -Wextra -Werror

FILES = input\
		input2\
		count\
		list_input\
		list_room\
		detection\
		detection2\
		main\
		adj_mat\
		link\
		stack\
		backtrack\
		output\

CFILES = $(FILES:%=./src/%.c)

OFILES = $(FILES:%=./obj/%.o)

CD_CFILES = $(FILES:%=../src/%.c)

all: $(NAME)
	@:

$(NAME): $(OFILES)
	@$(MAKE) -C ./libft/
	@$(CC) $^ ./libft/libft.a -o $@
	@printf "${RESET}[${YELLOW}BUILT LEM-IN${RESET}]\n"

$(OFILES): $(CFILES)
ifeq ("$(wildcard ./obj)","")
	@mkdir ./obj
endif
	@cd ./obj && $(CC) $(FLAGS) -c $(CD_CFILES) -I ../inc/

clean:
	@rm -f $(OFILES)
ifneq ("$(wildcard ./obj)","")
	@rmdir ./obj
endif
	@$(MAKE) clean -C ./libft/
	@printf "${RESET}[${YELLOW}CLEANED${RESET}]\n"

fclean:
	@rm -f $(OFILES)
ifneq ("$(wildcard ./obj)","")
	@rmdir ./obj
endif
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft/
	@printf "${RESET}[${YELLOW}FORCE CLEANED${RESET}]\n"

norm:
	@printf "${RESET}[${YELLOW}NORMING PROJECT${RESET}]\n"
	norminette -R CheckForbiddenSourceHeader ./src/
	norminette -R CheckForbiddenSourceHeader ./inc/
	@printf "${RESET}[${YELLOW}NORMING LIBRARY${RESET}]\n"
	norminette -R CheckForbiddenSourceHeader ./libft/ft_a*.c
	norminette -R CheckForbiddenSourceHeader ./libft/ft_b*.c
	norminette -R CheckForbiddenSourceHeader ./libft/ft_c*.c
	norminette -R CheckForbiddenSourceHeader ./libft/ft_d*.c
	norminette -R CheckForbiddenSourceHeader ./libft/ft_i*.c
	norminette -R CheckForbiddenSourceHeader ./libft/ft_l*.c
	norminette -R CheckForbiddenSourceHeader ./libft/ft_m*.c
	norminette -R CheckForbiddenSourceHeader ./libft/ft_p*.c
	norminette -R CheckForbiddenSourceHeader ./libft/ft_s*.c
	norminette -R CheckForbiddenSourceHeader ./libft/ft_t*.c
	norminette -R CheckForbiddenSourceHeader ./libft/get_next_line.c
	norminette -R CheckForbiddenSourceHeader ./libft/*.h

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean norm re
