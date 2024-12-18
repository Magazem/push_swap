# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 16:14:06 by ysuliman          #+#    #+#              #
#    Updated: 2024/11/10 19:46:57 by ysuliman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft

PUSH_SWAP_SRCS	= ft_check_sort.c utils.c push_swap.c ft_countspaces.c operations.c  operations2.c \
operations3.c ft_sort.c sort_big_stack.c ft_sort_5.c\

OBJS		= $(PUSH_SWAP_SRCS:.c=.o)

CC			= cc 
AR			= ar rcs
RM			= rm -rf 
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME) $(EXEC)

$(NAME):	$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./libft -lft				
				
$(LIBFT):	$(LIBFTDIR)
				@$(MAKE) -C $(LIBFTDIR)

clean:
			@$(MAKE) clean -C $(LIBFTDIR)
			@$(RM) $(OBJS)

fclean:		clean
				@$(MAKE) fclean -C $(LIBFTDIR)
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
