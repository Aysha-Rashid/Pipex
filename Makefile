NAME = pipex
SRC = main.c \
	child_process.c \
	init.c \

CFLAG = -Wall -Wextra -Werror
CC = cc

OBJ = $(SRC:.c=.o)
FT_PRINTF_PATH = ft_printf
LIBFT_PATH = libft
FT_PRINT_LIB = -L ${FT_PRINTF_PATH} -lft 
LIBFT_LIB = -L ${LIBFT_PATH} -lftprintf

$(NAME): $(OBJ)
	cd $(LIBFT_PATH) && make all
	cd $(FT_PRINTF_PATH) && make all
	$(CC) $(CFLAG) $(OBJ) $(FT_PRINT_LIB) $(LIBFT_LIB) -o $(NAME)

# $(FT_PRINT_LIB):
# 	cd $(FT_PRINTF_PATH) && make

# $(LIBFT_LIB):
# 	cd $(LIBFT_PATH) && make

all: $(NAME)

clean:
	rm -rf $(OBJ)
	@ cd $(LIBFT_PATH) && make clean
	@ cd $(FT_PRINTF_PATH) && make clean

fclean: clean
	rm -rf $(NAME)
	@ cd $(LIBFT_PATH) && make fclean
	@ cd $(FT_PRINTF_PATH)  && make fclean

re: fclean all