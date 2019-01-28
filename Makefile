# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/26 20:42:40 by lhernand          #+#    #+#              #
#    Updated: 2019/01/27 12:14:57 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors -lncurses
SRC = Game.cpp \
		Player.cpp \
		Enemy.cpp \
		Missile.cpp \
		Junk.cpp \
		main.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(SRC) $(CXXFLAGS) -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

Phony: all, clean, fclean, re
