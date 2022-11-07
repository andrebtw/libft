CC = gcc
AR = ar rc
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c  ft_strchr.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
		ft_strlen.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlcpy.c
HEADER = libft.h
NAME = libft.a
RM = rm -f

.c.o:
			${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:
			${RM} ${OBJS} ${NAME}

re:	fclean ${NAME}