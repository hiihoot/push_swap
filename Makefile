NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
SRCS        = helpers/free.c helpers/ft_bzero.c helpers/ft_calloc.c helpers/ft_memset.c \
			  helpers/ft_split.c helpers/ft_strdup.c helpers/ft_strjoin.c helpers/ft_strlcpy.c \
			  helpers/ft_strlen.c helpers/utils.c op/push.c op/rev_rotate.c op/rotate.c op/swap.c \
			  src/big_sort.c src/parsing.c src/push_swap.c src/small_sort.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re