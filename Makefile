#VARIABLES

NAME		= fdf

SRCS		= srcs/fdf/main.c	srcs/fdf/parsing.c	srcs/fdf/ft_put_line.c	srcs/fdf/window.c \
			srcs/fdf/color/ft_color_add_front.c srcs/fdf/color/ft_color_add_back srcs/fdf/color/ft_color_clear.c \
			srcs/fdf/color/ft_color_new.c srcs/fdf/color/ft_color_last.c srcs/fdf/color/ft_color_size.c

OBJS		= $(SRCS:%.c=%.o)

INCS		= includes/fdf.h includes/libft.h includes/get_next_line.h includes/mlx.h includes/mlx_int.h

LIBS		= lib/libft.a lib/libgnl.a lib/libmlx.a lib/libmlx_Linux.a

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
			${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME} -lXext -lX11 -lm -lz

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
