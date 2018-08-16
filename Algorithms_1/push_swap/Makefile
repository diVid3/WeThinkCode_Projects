# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egenis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 13:16:14 by egenis            #+#    #+#              #
#    Updated: 2018/08/16 09:13:06 by egenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = build

RED = \033[0;31m

WHITE = \033[0;37m

all: $(NAME)

$(NAME):
	@$(MAKE) -C ./src/checker/
	@$(MAKE) -C ./src/push_swap/

clean:
	@echo "[${RED}CLEANED${WHITE}]"
	@$(MAKE) clean -C ./src/checker/
	@$(MAKE) clean -C ./src/push_swap/
	@$(MAKE) clean -C ./libft/

fclean:
	@echo "[${RED}FORCE CLEANED${WHITE}]"
	@$(MAKE) fclean -C ./src/checker/
	@$(MAKE) fclean -C ./src/push_swap/
	@$(MAKE) fclean -C ./libft/

re: fclean all
