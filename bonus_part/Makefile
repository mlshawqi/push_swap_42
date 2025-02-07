NAME = checker

SRCS = main_bonus.c parsing_bonus.c parsing2_bonus.c operations_bonus.c clear_bonus.c\
		linked_list_bonus.c operations2_bonus.c read_bonus.c\
        ../libft/ft_split.c  ../libft/ft_isdigit.c ../libft/ft_atoi.c\
		../libft/ft_strlen.c ../libft/ft_lstadd_back.c ../libft/ft_calloc.c\
		../libft/ft_lstclear.c ../libft/ft_lstdelone.c ../libft/ft_strcmp.c\
		../ft_printf/ft_printf.c ../ft_printf/ft_format.c ../ft_printf/ft_putstr.c\
		../ft_printf/ft_putchar.c \
		../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c

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