# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egenis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 13:16:14 by egenis            #+#    #+#              #
#    Updated: 2018/08/16 13:34:19 by egenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m

WHITE = \033[0;37m

NAME = checker

FLAGS = -Wall -Wextra -Werror

FILES = ft_atol\
		ft_build_stacks\
		ft_check_arg\
		ft_check_min_max\
		ft_check_spaces\
		ft_count_nums\
		ft_do_ops\
		ft_join_args\
		ft_nxt_num_adrs\
		ft_print_stacks\
		ft_push\
		ft_r_rotate\
		ft_rotate\
		ft_swap\
		ft_validate_stack\
		main\

CFILES = $(FILES:%=./%.c)

OFILES = $(FILES:%=./%.o)

all: $(NAME)

$(NAME): $(OFILES)
	@$(MAKE) -C ../../libft/
	@gcc -o ../../$(NAME) $(OFILES) ../../libft/libft.a

$(OFILES): $(CFILES)
	@gcc -c $(FLAGS) $(CFILES) -I ../../inc/checker/

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f ../../$(NAME)

re: fclean all

.PHONY: all clean fclean re
