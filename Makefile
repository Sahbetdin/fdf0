NAME = fdf

# file names
SRC = main.c
OBJ = $(SRC:.c=.o)

# floders
SRCDIR = src
OBJDIR = objs
LIBDIR = libs/my_libft
MLXDIR = libs/minilibx

# files with their paths
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

# compiler
CC = gcc
W = -Wall -Werror -Wextra
HEADERS = -I includes -I $(LIBDIR)/includes -I $(MLXDIR)
# # final
# CFLAGS = -c -Wall -Werror -Wextra
# LIBS = -L $(LIBDIR) -lft -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit

# debug - fsanitize
CFLAGS = -c -g $(W) -fsanitize=address
LIBS = -L $(LIBDIR) -lft -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit -fsanitize=address

# # debug - VSCode lldb debugger
# CFLAGS = -c -g -Wall -Werror -Wextra 
# LIBS = -L $(LIBDIR) -lft -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit


RED = "\033[0;31m"
GREEN = "\033[0;32m"
WHITE = "\033[0m"

# prevent name collisions with files in the directory.
.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "[$(CC)] - $<"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(MLXDIR)
	make -C $(LIBDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "$(NAME) created"

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(MLXDIR) clean
# 	@make -C $(LIBDIR) clean
	@echo "$(NAME) cleaned"

fclean: clean
	@/bin/rm -f $(NAME)
# 	@make -C $(LIBDIR) fclean
	@echo "$(NAME) deleted"

re: fclean all
