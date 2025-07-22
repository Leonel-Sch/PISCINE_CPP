# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:01:19 by lscheupl          #+#    #+#              #
#    Updated: 2025/07/22 15:15:17 by lscheupl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.cpp

OBJ = *.o

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Phonebook

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) -c $(SRC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# %.o: %.cpp
# 	 $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re