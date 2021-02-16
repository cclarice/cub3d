# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 06:18:45 by cclarice          #+#    #+#              #
#    Updated: 2021/02/16 23:00:57 by cclarice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(VALID) $(ENGINE) $(UTILS) $(PRINTF)           ./src/cube3d.c \

VALID		=	./src/vld/vld.c					             ./src/vld/error.c \
				./src/vld/validmap.c                       ./src/vld/getvars.c \
				./src/vld/vldmap.c                          ./src/vld/vldind.c \

ENGINE		=	./src/engine/initialization.c   ./src/engine/initialization2.c \
				./src/engine/engine.c              ./src/engine/engine_utils.c \
				./src/engine/map_render.c           ./src/engine/window_init.c \
				./src/engine/my_string_put.c           ./src/engine/movement.c \
				./src/engine/draw.c                   ./src/engine/collision.c \
				./src/engine/raycasting.c                                      \
				./src/engine/tick.c                    ./src/engine/win_hook.c \
				./src/engine/keyboard.c                   ./src/engine/mouse.c \
				#./src/engine/engine.c \
				./src/engine/control.c                 ./src/engine/movement.c \
				./src/engine/mlx_utils.c                  ./src/engine/color.c \

UTILS		=   ./src/utils/get_file_size.c          ./src/utils/file_to_str.c \
				./src/utils/ft_strdup.c                  ./src/utils/ft_atoi.c \
				./src/utils/init_map.c              ./src/utils/check_dotcub.c \
				./src/utils/rgb_utils.c                ./src/utils/ft_strstr.c

PRINTF		=	./src/printf/ft_printf.c          ./src/printf/ft_printf_get.c \
				./src/printf/ft_printf_char.c     ./src/printf/ft_printf_hex.c \
				./src/printf/ft_printf_unsigned.c ./src/printf/ft_printf_str.c \
				./src/printf/ft_printf_utils.c    ./src/printf/ft_printf_nbr.c \
				./src/printf/ft_printf_put.c                                   \

CFLAGS		=	-I. -O3 -Wall -Wextra #-Werror
OBJS		=	$(SRCS:.c=.o)
LIBS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm
LMLX		=	libmlx.dylib
CC			=	cc
RM			=	rm -f

NAME		=	cub3D

all:
				$(NAME) -j 4

$(NAME):		$(MLX) $(OBJS)
				CC ${CFLAGS} $(LMLX) -o ${NAME} ${OBJS} ${LIBS}
$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

clean:	
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
