# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilib
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
LIB_NAME = libft.a

# List of source files
SRCS = $(SRC_DIR)/ft_atoi.c \
       $(SRC_DIR)/ft_bzero.c \
       $(SRC_DIR)/ft_calloc.c \
       $(SRC_DIR)/ft_isalnum.c \
       $(SRC_DIR)/ft_isalpha.c \
       $(SRC_DIR)/ft_isascii.c \
       $(SRC_DIR)/ft_isdigit.c \
       $(SRC_DIR)/ft_isprint.c \
       $(SRC_DIR)/ft_itoa.c \
       $(SRC_DIR)/ft_lstadd_back_bonus.c \
       $(SRC_DIR)/ft_lstadd_front_bonus.c \
       $(SRC_DIR)/ft_lstclear_bonus.c \
       $(SRC_DIR)/ft_lstdelone_bonus.c \
       $(SRC_DIR)/ft_lstiter_bonus.c \
       $(SRC_DIR)/ft_lstlast_bonus.c \
       $(SRC_DIR)/ft_lstmap_bonus.c \
       $(SRC_DIR)/ft_lstnew_bonus.c \
       $(SRC_DIR)/ft_lstsize_bonus.c \
       $(SRC_DIR)/ft_memchr.c \
       $(SRC_DIR)/ft_memcmp.c \
       $(SRC_DIR)/ft_memcpy.c \
       $(SRC_DIR)/ft_memmove.c \
       $(SRC_DIR)/ft_memset.c \
       $(SRC_DIR)/ft_print_adress_lower.c \
       $(SRC_DIR)/ft_print_adress_upper.c \
       $(SRC_DIR)/ft_print_adress.c \
       $(SRC_DIR)/ft_putchar_fd.c \
       $(SRC_DIR)/ft_putendl_fd.c \
       $(SRC_DIR)/ft_putlnbr.c \
       $(SRC_DIR)/ft_putnbr_fd.c \
	   $(SRC_DIR)/ft_putstr_fd.c \
       $(SRC_DIR)/ft_split.c \
       $(SRC_DIR)/ft_strchr.c \
       $(SRC_DIR)/ft_strdup.c \
       $(SRC_DIR)/ft_striteri.c \
       $(SRC_DIR)/ft_strjoin.c \
       $(SRC_DIR)/ft_strlcat.c \
       $(SRC_DIR)/ft_strlcpy.c \
       $(SRC_DIR)/ft_strlen.c \
       $(SRC_DIR)/ft_strmapi.c \
       $(SRC_DIR)/ft_strncmp.c \
       $(SRC_DIR)/ft_strnstr.c \
       $(SRC_DIR)/ft_strrchr.c \
       $(SRC_DIR)/ft_strtrim.c \
       $(SRC_DIR)/ft_substr.c \
       $(SRC_DIR)/ft_tolower.c \
       $(SRC_DIR)/ft_toupper.c \
       $(SRC_DIR)/get_next_line_utils.c \
       $(SRC_DIR)/get_next_line.c \
       $(SRC_DIR)/ft_printf.c

# Define object files corresponding to source files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	mkdir $(LIB_DIR)
	ar rcs $(LIB_DIR)/$(LIB_NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
