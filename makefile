# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 16:21:15 by ncruz-ga          #+#    #+#              #
#    Updated: 2023/12/20 12:11:52 by ncruz-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = push_swap_bonus

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

PUSH_SWAP = psuh_swap.a

PUSH_SWAP_BONUS = 

LIB = ar rcs

SRCS = push_swap.c\
		check_args.c\
		fill_stack.c\

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = 

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME):		$(OBJS) $(LIBFT)
					@$(LIB) $(PIPEX) $(OBJS)
					@$(CC) $(CFLAGS) $(PIPEX) $(LIBFT) -o $(NAME)

$(OBJS):		src/%.o : src/%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS):	$(OBJS_BONUS) $(LIBFT)
				@$(LIB) $(PIPEX_BONUS) $(OBJS_BONUS)
				@$(CC) $(CFLAGS) $(PIPEX_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):
				@make -s -C $(LIBFT_PATH)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:			
				@rm -f $(OBJS) $(OBJS_BONUS)
				@make clean -s -C $(LIBFT_PATH)

fclean:			
				@rm -f $(NAME) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT) $(PIPEX) $(PIPEX_BONUS)
				@make fclean -s -C $(LIBFT_PATH)

re: fclean all

pipe: all clean

.PHONY: all re fclean clean bonus