NAME		= fdf

DIR_SRCS	= ./srcs/fdf/

DIR_INCS	= ./includes/*.h

SRCS		= 

OBJS		= ${SRCS:.c=.o}

INCS		= fdf.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g3

