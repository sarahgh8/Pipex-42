.RECIPEPREFIX = ~
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = test.c
OBJ_FILE = obj
OBJ = $(addprefix $(OBJ_FILE)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
~$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_FILE)/%.o: %.c | $(OBJ_FILE)
~$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FILE):
~mkdir -p $(OBJ_FILE)

clean:
~rm -rf $(OBJ_FILE)
fclean: clean
~rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re