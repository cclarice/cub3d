# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 06:18:45 by cclarice          #+#    #+#              #
#    Updated: 2021/03/16 04:18:57 by cclarice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
BNAME		=	cub4D

SRCS		=	$(VALID) $(ENGINE) $(UTILS) $(PRINTF) $(LISTS) ./src/cube3d.c
BSRC		=	$(VALID) $(EBONUS) $(UTILS) $(PRINTF) $(LISTS) ./src/cube3d.c

VALID		=	./src/vld/vld.c					             ./src/vld/error.c \
				./src/vld/validmap.c                       ./src/vld/getvars.c \
				./src/vld/vldmap.c                          ./src/vld/vldind.c

ENGINE		=	./src/engine/initialization.c   ./src/engine/initialization2.c \
				./src/engine/engine.c              ./src/engine/engine_utils.c \
				./src/engine/window_init.c             ./src/engine/movement.c \
				./src/engine/draw.c                   ./src/engine/collision.c \
				./src/engine/raycasting.c                  ./src/engine/tick.c \
				./src/engine/win_hook.c                ./src/engine/keyboard.c \
				./src/engine/mouse.c             ./src/engine/raycasting_len.c \
				./src/engine/sprite.c               ./src/engine/sort_sprite.c \
				./src/engine/clear_sprites.c      ./src/engine/bmp/bmp_utils.c \
				./src/engine/bmp/ft_write_bmp.c

EBONUS		=	./src/ebonus/initialization.c   ./src/ebonus/initialization2.c \
				./src/ebonus/engine.c              ./src/ebonus/engine_utils.c \
				./src/ebonus/window_init.c             ./src/ebonus/movement.c \
				./src/ebonus/draw.c                   ./src/ebonus/collision.c \
				./src/ebonus/raycasting.c                  ./src/ebonus/tick.c \
				./src/ebonus/win_hook.c                ./src/ebonus/keyboard.c \
				./src/ebonus/mouse.c             ./src/ebonus/raycasting_len.c \
				./src/ebonus/sprite.c               ./src/ebonus/sort_sprite.c \
				./src/ebonus/clear_sprites.c      ./src/ebonus/bmp/bmp_utils.c \
				./src/ebonus/bmp/ft_write_bmp.c

UTILS		=   ./src/utils/get_file_size.c          ./src/utils/file_to_str.c \
				./src/utils/ft_strdup.c                  ./src/utils/ft_atoi.c \
				./src/utils/init_map.c              ./src/utils/check_dotcub.c \
				./src/utils/rgb_utils.c				./src/utils/ft_strstr.c

LISTS		=	./src/utils/lists/lists.c

PRINTF		=	./src/printf/ft_printf_unsigned.c ./src/printf/ft_printf_get.c \
				./src/printf/ft_printf_utils.c    ./src/printf/ft_printf_hex.c \
				./src/printf/ft_printf_char.c     ./src/printf/ft_printf_str.c \
				./src/printf/ft_printf_put.c      ./src/printf/ft_printf_nbr.c \
				./src/printf/ft_printf.c

CFLAGS		=	-I. -O3 -Wall -Wextra -Werror
OBJS		=	$(SRCS:.c=.o)
BOBJ		=	$(BSRC:.c=.o)

LIBS		=	-framework OpenGL -framework AppKit
MLX			=	libmlx.a
CC			=	cc
RM			=	rm -f

HEADERS 	= 	./src/utils/lists/lists.h             ./src/printf/ft_printf.h \
				./src/cube3d.h

BHEADERS	=	./src/ebonus/bmp/bmp_utils.h             ./src/ebonus/engine.h

SHEADERS	=	./src/engine/bmp/bmp_utils.h             ./src/engine/engine.h

all:			$(NAME)

$(NAME): 		$(MLX) $(OBJS) $(HEADERS) $(SHEADERS)
				CC ${CFLAGS} $(MLX) -o ${NAME} ${OBJS} ${LIBS}

bonus:			$(BNAME)

$(BNAME):		$(MLX) $(BOBJ) $(HEADERS) $(BHEADERS)
				CC ${CFLAGS} $(MLX) -o ${BNAME} ${BOBJ} ${LIBS}

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

clean:	
				@$(MAKE) -C mlx clean
				$(RM) $(BOBJ) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(BNAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
