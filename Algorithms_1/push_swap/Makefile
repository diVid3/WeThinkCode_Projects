# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egenis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 13:16:14 by egenis            #+#    #+#              #
#    Updated: 2018/08/15 17:33:46 by egenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: $(NAME)

$(NAME):
	$(MAKE) -C ./src/checker/
	$(MAKE) -C ./src/push_swap/

clean:
	$(MAKE) clean -C ./src/checker/
	$(MAKE) clean -C ./src/push_swap/
	$(MAKE) clean -C ./libft/

fclean:
	$(MAKE) fclean -C ./src/checker/
	$(MAKE) fclean -C ./src/push_swap/
	$(MAKE) fclean -C ./libft/

re: fclean all
