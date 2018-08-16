# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egenis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 13:16:14 by egenis            #+#    #+#              #
#    Updated: 2018/08/16 09:11:47 by egenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m

WHITE = \033[0;37m

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

FILES = ft_atol\
		ft_build_stacks\
		ft_check_arg\
		ft_check_min_max\
		ft_check_spaces\
		ft_count_nums\
		ft_join_args\
		ft_nxt_num_adrs\
		ft_push\
		ft_r_rotate\
		ft_rotate\
		ft_sort_stack\
		ft_sort_stack_rem_val\
		ft_swap\
		ft_validate_stack\
		main\

CFILES = $(FILES:%=./%.c)

OFILES = $(FILES:%=./%.o)

all: $(NAME)

$(NAME): $(OFILES)
	@echo "[${RED}BUILDING PUSH_SWAP${WHITE}]"
	@$(MAKE) fclean -C ../../libft/
	@$(MAKE) -C ../../libft/
	@gcc -o ../../$(NAME) $(OFILES) ../../libft/libft.a

$(OFILES): $(CFILES)
	@gcc -c $(FLAGS) $(CFILES) -I ../../inc/push_swap/

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f ../../$(NAME)

re: fclean all

.PHONY: all clean fclean re
