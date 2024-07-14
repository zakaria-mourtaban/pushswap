NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -g
SRCS = pushswapsrc/errhandleutils1.c pushswapsrc/errhandleutils2.c pushswapsrc/pushswap.c pushswapsrc/pushswap.h pushswapsrc/pushswapoperations.c pushswapsrc/pushswapoperations2.c pushswapsrc/pushswapoperations3.c pushswapsrc/pushswapoperations4.c pushswapsrc/pushswaputils.c pushswapsrc/pushswaputils2.c pushswapsrc/sortingalg.c pushswapsrc/sortutils.c
OBJS = $(SRCS:.c=.o)
BONUS = checker
BONUSSRCS = checker/checker.C
BONUSOBJS = $(BONUSSRCS:.c=.o)
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

$(BONUS): &(BONUSOBJS)
	gcc $(CFLAGS) $(BONUSOBJS) -o $(BONUS)

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

bonus : $(BONUS)

.PHONY: all clean fclean re bonus
