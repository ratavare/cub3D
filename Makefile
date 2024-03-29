# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 15:49:55 by apereira          #+#    #+#              #
#    Updated: 2024/02/14 16:26:24 by ratavare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## 		   NAMES 		##########

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm

RM = rm -rf

PRINTF = libft/ft_printf/libftprintf.a
MLX_PATH = ./includes/mlx_linux/libmlx_Linux.a

SRC = main.c parser/parser.c parser/map.c parser/parser_utils.c parser/parser_utils2.c parser/extract.c free.c error.c utils.c events.c math.c distance.c drawing.c drawing_aux.c moves.c minimap.c

SRC_GNL = libft/GNL/get_next_line.c libft/GNL/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
OBJ_GNL = $(SRC_GNL:.c=.o)

########## 		   TARGETS 		##########

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(addprefix src/,$(OBJ))  $(OBJ_GNL)
	@make -s -C libft/ft_printf
	@make -s -C libft
	@$(CC) $(addprefix src/,$(OBJ)) $(OBJ_GNL) $(MLX_PATH) -o $(NAME) $(PRINTF) libft/libft.a $(INCLUDES)

test: 
	./cub3D includes/maps/valid/normal.cub

git: fclean
	@git add .
	@git commit
	@git push
	@clear
	@echo "|                                                 |"
	@echo "|                                                 |"
	@echo "|      -------{ Commited and Pushed }-------      |"
	@echo "|                                                 |"
	@echo "|                                                 |"

commit: fclean

clean: 
	@make clean -s -C libft/ft_printf
	@make clean -s -C libft
	@$(RM) $(addprefix src/,$(OBJ))
	@$(RM) $(OBJ_GNL)

fclean: clean
	@make fclean -s -C libft/ft_printf
	@make fclean -s -C libft
	@$(RM) $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re