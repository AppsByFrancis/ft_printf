NAME = libftprintf.a
SRCS = ft_printf.c ft_functions.c
OBJS = $(SRCS:.c=.o)
CC = cc
INCS = ft_printf.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
