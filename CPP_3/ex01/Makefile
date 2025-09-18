# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leonel <leonel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 18:14:33 by leonel            #+#    #+#              #
#    Updated: 2025/09/18 19:40:39 by leonel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ScavTrap
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS		= main.cpp Claptrap.cpp ScavTrap.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re