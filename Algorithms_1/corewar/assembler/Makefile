# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egenis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 07:21:22 by egenis            #+#    #+#              #
#    Updated: 2018/09/11 07:21:24 by egenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW = \033[0;33m

RESET = \033[0m

NAME = asm

CC = clang

FLAGS = -Wall -Wextra -Werror

FILES = detection\
		detection2\
		detection3\
		detection4\
		detection5\
		input\
		labels\
		list_func\
		list_input\
		lockdown\
		main\
		op\
		split\
		strcdup\
		utils\

CFILES = $(FILES:%=./src/%.c)

OFILES = $(FILES:%=./obj/%.o)

CD_CFILES = $(FILES:%=../src/%.c)

all: $(NAME)
	@:

$(NAME): $(OFILES)
	@$(MAKE) -C ./libft/
	@$(CC) $^ ./libft/libft.a -o $@
	@printf "${RESET}[${YELLOW}BUILT ASSEMBLER${RESET}]\n"

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