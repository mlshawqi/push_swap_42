NAME = push_swap

SRCS = main.c parsing.c parsing2.c\
        libft/ft_split.c  libft/ft_isdigit.c libft/ft_atoi.c\
		libft/ft_strlen.c libft/ft_lstadd_back.c\
		libft/ft_lstclear.c libft/ft_lstdelone.c\

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.SECONDARY:$(OBJS)