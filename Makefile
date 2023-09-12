CC = cc
FLAGS = -Wall -Wextra -Werror -I.

SRCS = ft_printf.c \
ft_putchar.c \
ft_putnbr.c \
ft_putptr.c \
ft_putstr.c \
ft_strlen.c

OBJS := $(SRCS:%.c=%.o)

NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $^

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
