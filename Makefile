#VARIABLES

NAME		= fdf

SRCS		= srcs/main.c

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
			${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

clean		:
			@make clean -C srcs/libft
			@make clean -C srcs/gnl
			@make clean -C srcs/minilibx
			${RM} lib/* lib/ ${OBJS}

fclean		: clean
			${RM} ${NAME}

re			: fclean all

.PHONY		: all clean fclean re

%.o			: %.c
			${CC} ${CFLAGS} -c $< -o $@