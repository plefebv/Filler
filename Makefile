# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/04 11:19:04 by plefebvr          #+#    #+#              #
#    Updated: 2016/10/31 14:14:31 by plefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= plefebvr.filler

RM		= /bin/rm -rf

CFLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address

FILES	= 	main.c \
			utils.c \
			malloc.c \
			parts.c \
			algo.c \
			direction.c \
			algo_v.c

NORMAL = grab.c

COLOR =	grab_color.c \
		color.c

LIB	= -L libft -lft

all:	$(NAME)

CYN = tput bold ; tput setaf 6
RESET = tput sgr 0

$(NAME):
	@make -C libft
	@clang $(CFLAGS) $(FILES) $(NORMAL) $(LIB) -o $(NAME)
	@$(CYN)
	@echo " === Filler Compilation Done ===\n"
	@$(RESET)

color:
	@make -C libft
	@clang $(CFLAGS) $(FILES) $(COLOR) $(LIB) -o $(NAME)
	@$(CYN)
	@echo " === Filler Color Compilation Done ===\n"
	@$(RESET)

clean:
	@make -C libft clean
	@$(RM) .obj

fclean: clean
	@make -C libft fclean
	@$(RM) $(NAME)

re: fclean all

norme:
	norminette $(FILES) $(COLOR) filler.h

.PHONY: all make_libft clean fclean re norme color
