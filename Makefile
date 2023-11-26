

SRCS = libftprintf.a

OBJS =	${SRCS:.c=.c}

NAME = libftprintf.a

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -I./include

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re 
