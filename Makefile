# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 16:21:15 by ncruz-ga          #+#    #+#              #
#    Updated: 2024/10/21 19:35:17 by ncruz-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

PUSH_SWAP = push_swap.a

PUSH_SWAP_BONUS = checker.a

FILES = src/push_swap.c\
		src/parser/check_arg.c\
		src/algorithm/algorithm.c\
		src/algorithm/algorithm_utils3.c\
		src/algorithm/algorithm_utils.c\
		src/algorithm/algorithm_utils2.c\
		src/list/fill_stack.c\
		src/list/mov.c\
		src/list/mov2.c\
		src/list/mov3.c\

OBJECTS = $(FILES:.c=.o)

FILES_BONUS = srcb/checker.c

OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a

$(NAME):			$(OBJECTS) $(LIBFT)
						@ar rcs $(PUSH_SWAP) $(OBJECTS)
						@gcc $(FLAGS) $(PUSH_SWAP) $(LIBFT) $(LIB_SYS) -o $(NAME)

$(NAME_BONUS):		$(OBJECTS_BONUS) $(OBJECTS) $(LIBFT)
						@ar rcs $(PUSH_SWAP_BONUS) $(OBJECTS_BONUS) $(OBJECTS)
						@gcc $(FLAGS) $(PUSH_SWAP_BONUS) $(LIBFT) $(LIB_SYS) -o $(NAME_BONUS)

$(OBJECTS):	src/%.o : src/%.c
						@gcc $(FLAGS) -c $< -o $@

$(OBJECTS_BONUS):	srcb/%.o : srcb/%.c
						@gcc $(FLAGS) -c $< -o $@

$(LIBFT):
					@make -s -C ./libft

all:				$(NAME)

bonus:				$(NAME_BONUS)

clean:
					@ rm -f $(OBJECTS) $(OBJ_BONUS)
					@ make clean -s -C ./libft

fclean:
					@ rm -f $(NAME) $(NAME_BONUS) $(OBJECTS) $(OBJECTS_BONUS) $(PUSH_SWAP) $(PUSH_SWAP_BONUS) $(LIBFT)
					@ make fclean -s -C ./libft

re:					fclean all

.PHONY: all re clean fclean bonus