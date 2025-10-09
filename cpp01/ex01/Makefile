NAME := zombiehorde
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I include
SRC_DIR := src
OBJ_DIR := obj
INCLUDE_DIR := include

SRCS := $(SRC_DIR)/Zombie.cpp $(SRC_DIR)/main.cpp $(SRC_DIR)/zombieHorde.cpp
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re