# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 19:14:45 by lenygarcia        #+#    #+#              #
#    Updated: 2025/05/07 11:14:39 by lenygarcia       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g -Ilibft/includes -Iincludes -Iminilibx
SRCS		= srcs/main.c srcs/error.c srcs/map.c srcs/free_func.c srcs/parse_map.c \
		srcs/parse_map_char.c srcs/test_path.c srcs/error2.c srcs/player_move.c \
		srcs/create_map.c srcs/gameplay_utils.c srcs/enemy.c
OBJS		= $(SRCS:.c=.o)
NAME		= so_long
LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a
MLX_DIR		= ./minilibx
MLX		= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLX)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
