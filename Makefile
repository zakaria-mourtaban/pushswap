NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -g
SRCS = pushswapsrc/errhandleutils1.c \
       pushswapsrc/errhandleutils2.c \
       pushswapsrc/pushswap.c \
       pushswapsrc/pushswapoperations.c \
       pushswapsrc/pushswapoperations2.c \
       pushswapsrc/pushswapoperations3.c \
       pushswapsrc/pushswapoperations4.c \
       pushswapsrc/pushswaputils.c \
       pushswapsrc/pushswaputils2.c \
       pushswapsrc/sortingalg.c \
       pushswapsrc/sortutils.c
OBJS = $(SRCS:.c=.o)
BONUS = checker
BONUS_SRCS = checkersrc/checker.c \
	   		 pushswapsrc/errhandleutils1.c \
	  		 pushswapsrc/errhandleutils2.c \
	 		 pushswapsrc/pushswapoperations.c \
	 		 pushswapsrc/pushswapoperations2.c \
			 pushswapsrc/pushswapoperations3.c \
			 pushswapsrc/pushswapoperations4.c \
			 pushswapsrc/pushswaputils.c \
			 pushswapsrc/pushswaputils2.c \
			 pushswapsrc/sortingalg.c \
			 pushswapsrc/sortutils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Paths to ft_printf and libft directories
PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./libft

# Targets
all: $(NAME) $(BONUS)

$(NAME): $(OBJS)
	@make -C $(PRINTF_DIR)
	@make -C $(LIBFT_DIR)
	gcc $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o $(NAME)

$(BONUS): $(BONUS_OBJS)
	@make -C $(PRINTF_DIR)
	@make -C $(LIBFT_DIR)
	gcc $(CFLAGS) $(BONUS_OBJS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o $(BONUS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	@make -C $(PRINTF_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	@make -C $(PRINTF_DIR) fclean
	@make -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(BONUS)

.PHONY: all clean fclean re bonus
