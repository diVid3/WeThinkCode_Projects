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

RED = \033[0;31m

WHITE = \033[0;37m

NAME = lem-in

FLAGS = -Wall -Wextra -Werror

FILES = main\

CFILES = $(FILES:%=./src/%.c)

OFILES = $(FILES:%=./obj/%.o)

all: $(NAME)
	@:

$(NAME): $(OFILES)
	@$(MAKE) -C ./libft/
	@gcc $^ ./libft/libft.a -o $@
	@printf "[${RED}BUILT LEM-IN${WHITE}]\n"

$(OFILES): $(CFILES)
ifeq ("$(wildcard ./obj)","")
	@mkdir ./obj
endif
	@gcc $(FLAGS) -c $^ -I ./inc/ -o $@

clean:
	@rm -f $(OFILES)
ifneq ("$(wildcard ./obj)","")
	@rmdir ./obj
endif
	@$(MAKE) clean -C ./libft/
	@printf "[${RED}CLEANED${WHITE}]\n"

fclean:
	@rm -f $(OFILES)
ifneq ("$(wildcard ./obj)","")
	@rmdir ./obj
endif
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft/
	@printf "[${RED}FORCE CLEANED${WHITE}]\n"

norm:
	@printf "[${RED}NORMING PROJECT${WHITE}]\n"
	norminette -R CheckForbiddenSourceHeader ./src/
	@printf "[${RED}NORMING LIBRARY${WHITE}]\n"
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

re: fclean all

.PHONY: all clean fclean norm re
