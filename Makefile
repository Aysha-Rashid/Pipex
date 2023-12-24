NAME = pipex
SRC = pipex.c \
	child_process.c \
	parent_process.c \

CFLAG = -Wall -Wextra -Werror
CC = cc

OBJ = $(SRC:.c=.o)
FT_PRINTF_PATH = ft_printf
FT_PRINT_LIB = ft_printf/libftprintf.a
LIBFT_PATH = libft
LIBFT_LIB = libft/libft.a

$(NAME): $(OBJ) $(FT_PRINT_LIB) $(LIBFT_LIB)
	@ $(CC) $(CFLAG) -o $(NAME) $(OBJ) $(FT_PRINT_LIB) $(LIBFT_LIB) 

$(FT_PRINT_LIB):
	@ $(MAKE) -C $(FT_PRINTF_PATH)

$(LIBFT_LIB):
	@ $(MAKE) -C $(LIBFT_PATH)

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