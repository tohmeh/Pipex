# Variables
NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = LIBFT
LIBFT = $(LIBFT_DIR)/lib/libft.a
SRCS = pipex.c handle_commands.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I $(LIBFT_DIR)/include

# Rules
all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
