NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra 

SRCS	=

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:


fclean: clean

re: fclean all

.PHONY: all clean fclean norm re bonus