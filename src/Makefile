


NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
SRCS        = push_swap.c free.c parsing.c ft_bzero.c ft_calloc.c \
              ft_memset.c ft_split.c ft_strjoin.c ft_strlcpy.c ft_strlen.c \
			  ft_strdup.c rev_rotate.c rotate.c push.c utils.c swap.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re