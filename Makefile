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
		ft_split.c
HEADER = libft.h
NAME = libft.a

#### BONUS FILES ####
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c
HEADER_BONUS = libft_bonus.h
NAME_BONUS = libft.a


#### RULES ####
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:
			${RM} ${OBJS} ${NAME}

re:	fclean ${NAME}

bonus:		${OBJS_BONUS}
			${AR} ${NAME_BONUS} ${OBJS_BONUS}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS_BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJS_BONUS)