
NAME := megaphone
CCFLAGS := -Wall -Wextra -Werror
CC := c++
SRC_DIR := src

SRCS := $(SRC_DIR)/megaphone.cpp \

OBJS := $(SRCS:%.cpp=%.o)

$(NAME): $(OBJS)
		ar -rcs $@ $^

%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) -Iinclude -c $< -o $@

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re			