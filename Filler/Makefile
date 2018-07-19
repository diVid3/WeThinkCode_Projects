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

FILES =	src/ft_get_input\
		src/ft_get_map\
		src/ft_get_map_size\
		src/ft_get_piece\
		src/ft_get_piece_size\
		src/ft_get_player_num\
		src/ft_make_move_list\
		src/ft_optimizer\
		src/ft_place_piece\
		src/ft_players_exist\
		src/ft_rate_moves\
		src/ft_verify_move\
		src/main\

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
