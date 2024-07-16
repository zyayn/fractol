# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchia <zchia@42.sg>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/07 01:49:45 by zchia             #+#    #+#              #
#    Updated: 2024/07/07 01:49:45 by zchia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC		= gcc
CFLAGS	= -g -Werror -Wextra -Wall

MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

FTPRINTF_PATH	= ft_printf/
FTPRINTF_NAME	= libftprintf.a
FTPRINTF		= $(FTPRINTF_PATH)$(FTPRINTF_NAME)

INC			=	-I minilibx-linux/ \
				-I libft \
				-I ft_printf \

SRC_PATH	=	src/
SRC			=	fractol.c \
				init_exit.c \
				instructions.c \
				events.c \
				image.c \
				fractals.c 

SRCS		= $(addprefix $(SRC))

OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(FTPRINTF) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(MLX):
	@echo "Making minilibx..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(FTPRINTF):
	@echo "Making ft_printf..."
	@make -sC $(FTPRINTF_PATH)

$(NAME): $(OBJS)
	@echo "Making fract'ol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(FTPRINTF) $(INC) -lXext -lX11 -lm
	@echo "Fract'ol is ready."

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(FTPRINTF_PATH)

fclean: clean
	@echo "Removing fract'ol..."
	@rm -rf $(NAME)
	@rm -rf $(LIBFT_PATH)$(LIBFT_NAME)
	@rm -rf $(FTPRINTF_PATH)$(FTPRINTF_NAME)

re: fclean all

.PHONY: all re clean fclean