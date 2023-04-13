SRCS	=	main.c get_args.c utils.c actions.c

OBJS	= ${SRCS:.c=.o}

NAME	= philo

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
				${RM} ${OBJBS} ${OBJS}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re