
NAME := libftprintf.a
HEADERS := include/ft_printf.h
CCFLAGS := -Wall -Wextra -Werror
CC := c++
SRC_DIR := src

#SRCS := $(wildcard src/*.c)
SRCS := $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_putstr.c \
		$(SRC_DIR)/ft_putdec.c $(SRC_DIR)/ft_putdecu.c \
		$(SRC_DIR)/ft_puthexlower.c $(SRC_DIR)/ft_puthexupper.c \
		$(SRC_DIR)/ft_putptr.c \

OBJS := $(SRCS:%.c=%.o)

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