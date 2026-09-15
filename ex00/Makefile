# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 12:28:13 by bfaechti          #+#    #+#              #
#    Updated: 2026/01/30 15:09:27 by bfaechti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I include

# Files
SRC =	source/main.cpp \
		source/Bureaucrat.cpp

#Objects
OBJ_DIR = object
OBJ = $(SRC:source/%.cpp=$(OBJ_DIR)/%.o)

NAME = bureaucrat

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# Compile Rule
$(OBJ_DIR)/%.o: source/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all