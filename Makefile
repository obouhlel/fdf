#VARIABLES

NAME		= fdf

NAME_LIB	= libfdf.a

SRCS		=  srcs/fdf/color/ft_color_add_back.c srcs/fdf/color/ft_color_add_front.c \
			srcs/fdf/color/ft_color_clear.c srcs/fdf/color/ft_color_last.c srcs/fdf/color/ft_color_new.c \
			srcs/fdf/color/ft_color_size.c srcs/fdf/map/ft_map_add_back.c srcs/fdf/map/ft_map_add_front.c \
			srcs/fdf/map/ft_map_clear.c srcs/fdf/map/ft_map_last.c srcs/fdf/map/ft_map_new.c \
			srcs/fdf/map/ft_map_size.c srcs/fdf/ft_put_line.c srcs/fdf/main.c srcs/fdf/parsing.c \
			srcs/fdf/check_parsing.c srcs/fdf/vars.c srcs/fdf/window.c

OBJS		= $(SRCS:%.c=%.o)

INCS		= includes/fdf.h includes/libft.h includes/get_next_line.h includes/mlx.h includes/mlx_int.h

LIBS		= lib/libfdf.a lib/libft.a lib/libgnl.a lib/libmlx.a lib/libmlx_Linux.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g3

AR			= ar rcs

RM			= rm -rf

#RULES

all			: ${NAME}

${NAME}		: ${OBJS} ${INCS}
			mkdir -p lib
			@make -C srcs/libft
			@mv srcs/libft/libft.a lib/
			@make -C srcs/gnl
			@mv srcs/gnl/libgnl.a lib/
			@make -C srcs/minilibx
			@mv srcs/minilibx/libmlx.a lib/
			@mv srcs/minilibx/libmlx_Linux.a lib/
			${AR} ${NAME_LIB} ${OBJS}
			@mv ${NAME_LIB} lib/
			${CC} ${CFLAGS} ${LIBS} -o ${NAME} -lXext -lX11 -lm -lz

clean		:
			@make clean -C srcs/libft
			@make clean -C srcs/gnl
			@make clean -C srcs/minilibx
			${RM} lib/* lib/ ${OBJS}

fclean		: clean
			${RM} ${NAME}

re			: fclean all

norme		:
			@norminette includes/fdf.h includes/libft.h includes/get_next_line.h
			@norminette srcs/fdf/ srcs/libft/ srcs/gnl/

.PHONY		: all clean fclean re norme

%.o         : %.c
	        ${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@
