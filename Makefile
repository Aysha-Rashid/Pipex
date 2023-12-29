NAME = pipex
SRC = main.c \
	child_process.c \
	init.c \
	error_handling.c \
	path.c \

CFLAG = -Wall -Wextra -Werror
CC = cc

OBJ = $(SRC:.c=.o)
LIBFT_PATH = libft
LIBFT_LIB = -L ${LIBFT_PATH} -lft

$(NAME): $(OBJ)
	cd $(LIBFT_PATH) && make all
	$(CC) $(CFLAG) $(OBJ) $(LIBFT_LIB) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)
	@ cd $(LIBFT_PATH) && make clean

fclean: clean
	rm -rf $(NAME)
	@ cd $(LIBFT_PATH) && make fclean

re: fclean all