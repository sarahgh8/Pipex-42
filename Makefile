#Customization:
MAKEFLAGS += --no-print-directory
.RECIPEPREFIX = ~
PINK_BOLD = \033[1;38;5;206m
END = \033[0m
GREEN = \033[38;5;71m
RED = \033[38;5;204m

#Essentials:
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -Llibft -lft
SRC = test.c utils.c
OBJ_FILE = obj
OBJ = $(addprefix $(OBJ_FILE)/, $(SRC:.c=.o))
LIBFT = libft.a
LIBFT_DIR = libft

#Rules:

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) 
~@echo "$(GREEN)Compiling $(NAME)...$(END)"
~@echo "$(PINK_BOLD)DONE !$(END)"
~@$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_FILE)/%.o: %.c | $(OBJ_FILE)
~@echo "$(GREEN)Creating object files...$(END)"
~@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FILE):
~@mkdir -p $(OBJ_FILE)

$(LIBFT):
~@echo "$(GREEN)Creating $(LIBFT)..."
~@make -C $(LIBFT_DIR)

clean:
~@echo "$(RED)Deleting object files..."
~@rm -rf $(OBJ_FILE)
~@make clean -C $(LIBFT_DIR)

fclean: clean
~@echo "$(RED)Deleting $(NAME) and $(LIBFT)..."
~@rm -f $(NAME)
~@make fclean -C $(LIBFT_DIR)

re: fclean all

PHONY: all clean fclean re