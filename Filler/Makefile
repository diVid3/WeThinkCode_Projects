# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egenis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 12:38:07 by egenis            #+#    #+#              #
#    Updated: 2018/07/09 12:37:11 by egenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

FLAGS = -Wall -Wextra -Werror

FILES =	ft_get_input ft_get_map ft_get_map_size ft_get_piece\
		ft_get_piece_size ft_get_player_num ft_make_move_list\
		ft_optimizer ft_place_piece ft_players_exist\
		ft_rate_moves ft_verify_move main\

CFILES = $(FILES:=.c)

OFILES = $(FILES:=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) -C ./libft/
	$(MAKE) -C ./libft/ clean
	gcc -o $(NAME) $(OFILES) ./libft/libft.a

$(OFILES): $(CFILES)
	gcc -c $(FLAGS) $(CFILES) -I ./inc/

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
