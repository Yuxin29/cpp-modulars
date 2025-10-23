NAME := WithBrain
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17 -I include
SRC_DIR := src
OBJ_DIR := obj
INCLUDE_DIR := include

SRCS := $(SRC_DIR)/Animal.cpp $(SRC_DIR)/WrongAnimal.cpp  $(SRC_DIR)/Cat.cpp $(SRC_DIR)/WrongCat.cpp $(SRC_DIR)/Dog.cpp $(SRC_DIR)/Brain.cpp $(SRC_DIR)/main.cpp
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