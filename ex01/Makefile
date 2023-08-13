# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 11:59:25 by mcutura           #+#    #+#              #
#    Updated: 2023/08/12 11:59:25 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Targets ---
NAME := a.out
# --- Sources ---
SRCS := main.cpp ClapTrap.cpp ScavTrap.cpp
# --- Objects ---
OBJS := $(patsubst %.cpp, %.o, $(SRCS))
# --- Headers ---
HDRS := ClapTrap.hpp ScavTrap.hpp
# --- Compilers ---
CC := gcc
CXX := g++
# --- Flags ---
CFLAGS := -Wall -Wextra -Werror -pedantic-errors
debug: CFLAGS += -ggdb3
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic-errors
debug: CXXFLAGS += -ggdb3
# --- Utils --
RM := rm -rf

# --- Rules ---
all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	
$(OBJS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

debug: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean debug fclean re
