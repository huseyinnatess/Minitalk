NAME1 = server
NAME2 = client
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS1 = server.c

SRCS2 = client.c

OBJS1 = $(SRCS1:%.c=%.o)

OBJS2 = $(SRCS2:%.c=%.o)

all: $(NAME1) $(NAME2)

$(NAME1) : $(OBJS1)
	$(CC) $(CFLAGS) $(SRCS1) -o $(NAME1)

$(NAME2) : $(OBJS2)
	$(CC) $(CFLAGS) $(SRCS2) -o $(NAME2)

clean:
	$(RM) $(OBJS1) $(OBJS2)

fclean: clean
		$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re