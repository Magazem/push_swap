NAME		= push_swap

LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft
LIBFT_URL = https://github.com/Magazem/libft.git

PUSH_SWAP_SRCS	= ft_check_sort.c utils.c push_swap.c ft_countspaces.c operations.c  operations2.c \
operations3.c ft_sort.c sort_big_stack.c ft_sort_5.c\

OBJS		= $(PUSH_SWAP_SRCS:.c=.o)

CC			= cc 
AR			= ar rcs
RM			= rm -rf 
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME) $(EXEC)

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) --no-print-directory bonus -C $(LIBFTDIR)

$(LIBFTDIR):
	@echo "$(CYAN)Downloading libft...$(NORMAL)"
	git clone -q $(LIBFT_URL) $(LIBFTDIR)
	@echo "$(GREEN)Libft downloaded successfully$(NORMAL)"

$(NAME):	$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./libft -lft

clean:
			@$(MAKE) clean -C $(LIBFTDIR)
			@$(RM) $(OBJS)

fclean:		clean
				@${RM} ${LIBFTDIR}
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
