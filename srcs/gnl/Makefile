SRCS		:= get_next_line.c get_next_line_utils.c

OBJS_FOLDER	:= ../../objs/

OBJS		:= $(SRCS:.c=.o)

OBJS		:= $(addprefix $(OBJS_FOLDER),$(OBJS))

DEPS		:= $(OBJS:.o=.d)

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror -g3 -MMD

NAME		:= libgnl.a

AR			:= ar rcs

RM			:= rm -f

#RULES

all		: ${NAME}

${NAME}	: ${OBJS}
		${AR} ${NAME} ${OBJS}

clean	:
		${RM} ${OBJS}

fclean	: clean
		${RM} ${NAME}

re		: fclean all

.PHONY	: all clean fclean re

-include $(DEPS)

$(OBJS_FOLDER)%.o	: %.c
			mkdir -p $(@D)
	        ${CC} ${CFLAGS} -c $< -o $@
