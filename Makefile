#### SYSTEM ####
CC = gcc
AR = ar rc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

#### FILES ####
OBJS = ${SRCS:.c=.o}
SRCS = ft_atoi.c  ft_strchr.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
		ft_strlen.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlcpy.c \
		ft_substr.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c \
		ft_split.c ft_split2.c ft_strmapi.c ft_striteri.c
HEADER = libft.h

#### BONUS FILES ####
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c
HEADER_BONUS = libft_bonus.h

NAME = libft.a

#### RULES ####
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJS_BONUS} 

fclean:
			${RM} ${OBJS} ${OBJS_BONUS} ${NAME}

re:	fclean ${NAME}

bonus:		${OBJS_BONUS}
			${AR} ${NAME} ${OBJS_BONUS}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS_BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJS_BONUS)