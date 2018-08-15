# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egenis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 13:16:14 by egenis            #+#    #+#              #
#    Updated: 2018/08/15 16:12:58 by egenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

FLAGS = -Wall -Wextra -Werror

FILES = ft_atol.c\
		ft_build_stacks.c\
		ft_check_arg.c\
		ft_check_min_max.c\
		ft_check_spaces.c\
		ft_count_nums.c\
		ft_do_ops.c\
		ft_join_args.c\
		ft_nxt_num_adrs.c\
		ft_print_stacks.c\
		ft_push.c\
		ft_r_rotate.c\
		ft_rotate.c\
		ft_swap.c\
		ft_validate_stack.c\
		main.c\

CFILES = $(FILES:%=./%.c)

OFILES = $(FILES:%=./%.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) -C ../../libft/
	gcc -o $(NAME) $(OFILES) ../../libft/libft.a

$(OFILES): $(CFILES)
	gcc -c $(FLAGS) $(CFILES) -I ../../inc/checker/

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
