NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -g
SRCS = pushswap.c pushswaputils.c pushswaputils2.c pushswapoperations.c pushswapoperations2.c pushswapoperations3.c errhandleutils2.c errhandleutils1.c
OBJS = $(SRCS:.c=.o)
#REMOVE THE G FLAG WHEN DONE
# Paths to ft_printf and libft directories
PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./libft

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	# Compile ft_printf
	@make -C $(PRINTF_DIR)
	# Compile libft
	@make -C $(LIBFT_DIR)
	# Link everything together
	gcc $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(PRINTF_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
