NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra 
SRCS	= error_handling.c ft_split.c main.c push_swap.c push.c \
reverse_rotate.c rotate.c sort_little_lists.c stack_init_utils.c \
stack_init.c swap.c utils.c

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean norm re