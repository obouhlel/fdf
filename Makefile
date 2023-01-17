#VARIABLES

NAME		:= fdf

NAME_LIB	:= libfdf.a

SRCS		:= srcs/fdf/main.c srcs/fdf/vars.c \
            srcs/fdf/list/ft_lst_add_back.c srcs/fdf/list/ft_lst_last.c srcs/fdf/list/ft_lst_new.c srcs/fdf/list/ft_lst_clear.c \
			srcs/fdf/parsing.c srcs/fdf/check_parsing.c \
			srcs/fdf/projection.c srcs/fdf/pixel.c srcs/fdf/find_1.c srcs/fdf/find_2.c srcs/fdf/find_3.c \
			srcs/fdf/trace.c srcs/fdf/put_line.c srcs/fdf/window.c

OBJS_FOLDER	:= ./objs/

OBJS		:= $(SRCS:.c=.o)

OBJS		:= $(addprefix $(OBJS_FOLDER),$(OBJS))

DEPS		:= $(OBJS:.o=.d)

LIBS		:= lib/libfdf.a lib/libft.a lib/libgnl.a lib/libmlx.a lib/libmlx_Linux.a

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror -g3 -MMD

AR			:= ar rcs

RM			:= rm -rf

#RULES

all			: ${NAME}

${NAME}		: ${OBJS}
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
			${RM} lib/* lib/ ${OBJS_FOLDER} ${OBJS} ${DEPS}

fclean		: clean
			${RM} ${NAME}

re			: fclean all

norme		:
			@norminette includes/fdf.h includes/libft.h includes/get_next_line.h
			@norminette srcs/fdf/ srcs/libft/ srcs/gnl/

.PHONY		: all clean fclean re norme

-include $(DEPS)

$(OBJS_FOLDER)%.o	: %.c
			mkdir -p $(@D)
	        ${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@
