NAME=libftprintf.a
OBJECTS=ft_printf.o
CC=gcc
CFLAGS=-Wall -Wextra -Werror

# Default target
all: $(NAME)

# Build the static library
$(NAME): $(OBJECTS)
	ar rcs $@ $^

# Compile .o files from .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJECTS)

# Clean object files and static library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
