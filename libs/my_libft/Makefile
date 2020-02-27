NAME = libft.a

# floders
OBJ_DIR = objects
SRC_DIR = sources

# files with paths
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# compiler options
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
HEADERS = -I ./includes

# colors
RED = "\033[0;31m"
GREEN = "\033[0;32m"
WHITE = "\033[0m"
WHITE_B = "\033[1m"


# prevents name collision with files in current folder
.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) $< -o $@
	@echo Libft: $(GREEN) $< $(WHITE)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo $(WHITE_B) $(NAME)$(WHITE) created

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@echo $(WHITE_B) $(NAME)$(WHITE) cleaned

fclean: clean
	@/bin/rm -f $(NAME)
	@echo $(WHITE_B) $(NAME)$(WHITE) deleted

re: fclean all