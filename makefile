# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 16:21:15 by ncruz-ga          #+#    #+#              #
#    Updated: 2023/12/21 15:01:30 by ncruz-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

PUSH_SWAP = push_swap.a

LIB = ar rcs

SRCS = src/push_swap.c\
		src/check_arg.c\
		src/fill_stack.c\
		src/mov.c\
		src/mov_2.c\
		src/mov_3.c\
		src/algorithm_utils.c\
		src/algorithm.c\
		

OBJS = $(SRCS:.c=.o)


$(NAME):		$(OBJS) $(LIBFT)
					@$(LIB) $(PUSH_SWAP) $(OBJS)
					@$(CC) $(CFLAGS) $(PUSH_SWAP) $(LIBFT) -o $(NAME)

$(OBJS):		src/%.o : src/%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
				@make -s -C $(LIBFT_PATH)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:			
				@rm -f $(OBJS)
				@make clean -s -C $(LIBFT_PATH)

fclean:			
				@rm -f $(NAME) $(OBJS) $(LIBFT) $(PUSH_SWAP)
				@make fclean -s -C $(LIBFT_PATH)

re: fclean all

pipe: all clean

.PHONY: all re fclean clean bonus