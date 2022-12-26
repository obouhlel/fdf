SRCS	= get_next_line.c get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

INCS	= ../../includes/get_next_line.h

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g3

NAME	= libgnl.a

AR		= ar rcs

RM		= rm -f

#RULES

all		: ${NAME}

${NAME}	: ${OBJS} ${INCS}
		${AR} ${NAME} ${OBJS}

clean	:
		${RM} ${OBJS}

fclean	: clean
		${RM} ${NAME}

re		: fclean all

.PHONY	: all clean fclean re

%.o		: %.c
		${CC} ${CFLAGS} -c $< -o $@
