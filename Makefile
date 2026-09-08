# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 15:08:56 by ullorent          #+#    #+#              #
#    Updated: 2023/05/19 18:20:46 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CSRC = c3_main.c \
c3_map.c \
c3_raycast.c \
c3_raycast_wall.c \
c3_hooks.c \
c3_movements.c \
c3_rotation.c \
mapcheck/c3_map_args_getter.c \
mapcheck/c3_map_args_error.c \
mapcheck/c3_map_is_closed_check.c \
utils/modified_libft_funs.c \
utils/c3_free_mem.c \
utils/c3_init_funs.c \
utils/c3_texture_init_funs.c \
utils/c3_other_utils.c \
utils/c3_map_saving_utils.c \
utils/c3_mouse_camera_utils.c

OSRC = $(CSRC:.c=.o)
HFILE = cub3d.h

CFLAGS = -Wall -Werror -Wextra -O2 #-g3 -fsanitize=address
GCCCMD = gcc

all: $(NAME)

$(NAME): $(OSRC) $(HFILE)
	@echo "\033[33mCompiling libft library...\033[0m"
	@make -C libft
	@echo "\033[33mCompiling miniLibX library...\033[0m"
	@make -C mlx
	@$(GCCCMD) $(CFLAGS) ./libft/libft.a -Imlx -Icub3d.h -Lmlx -lmlx -framework OpenGL -framework AppKit $(CSRC) -o $(NAME)
	@echo "\033[92mcub3d has been successfully compiled!\033[0m"

clean:
	@make -C libft/ clean
	@make -C mlx/ clean
	@rm -f $(OSRC)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "\033[33mAll has been cleaned!\033[0m"

bonus:
	@echo "\033[33mbonus is compiling...\033[0m"
	@make re

re: fclean all

.PHONY: all clean fclean bonus re