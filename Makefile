NAME        = push_swap
BONUS_NAME	= checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
SRCS        = $(wildcard helpers/*.c) $(wildcard op/*.c) $(wildcard src/*.c)
BONUS_SRCS  = $(wildcard checker/*.c)
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