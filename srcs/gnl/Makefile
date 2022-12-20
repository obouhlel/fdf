SRCS	= get_next_line_utils.c get_next_line.c

OBJS	= ${SRCS:.c=.o}

INCS	= get_next_line.h

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -g3

NAME	= libgnl.a

all		: ${NAME}

${NAME}	: ${OBJS} ${INCS}
		ar rcs ${NAME} ${OBJS}

clean	:
		rm -f ${OBJS}

fclean	: clean
		rm -f ${NAME}

re		: all fclean

%.o		: %.c
		${CC} ${CFLAGS} -c $< -o $@

.PHONY	: all clean fclean re