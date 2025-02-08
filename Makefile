SRCS = mdtry_part/main.c mdtry_part/parsing.c mdtry_part/parsing2.c mdtry_part/algo_simple.c\
		mdtry_part/operations.c mdtry_part/clear.c mdtry_part/operations_b.c\
		mdtry_part/algo_complex.c mdtry_part/linked_list.c  mdtry_part/move_utils.c\
        libft/ft_split.c  libft/ft_isdigit.c libft/ft_atoi.c\
		libft/ft_strlen.c libft/ft_lstadd_back.c libft/ft_calloc.c\
		libft/ft_lstclear.c libft/ft_lstdelone.c \
		ft_printf/ft_printf.c ft_printf/ft_format.c ft_printf/ft_putstr.c\
		ft_printf/ft_putchar.c \

SRCB = bonus_part/main_bonus.c bonus_part/parsing_bonus.c bonus_part/parsing2_bonus.c\
		bonus_part/operations_bonus.c bonus_part/clear_bonus.c bonus_part/ft_sort_bonus.c\
		bonus_part/linked_list_bonus.c bonus_part/operations2_bonus.c bonus_part/read_bonus.c\
		libft/ft_split.c  libft/ft_isdigit.c libft/ft_atoi.c\
		libft/ft_strlen.c libft/ft_lstadd_back.c libft/ft_calloc.c\
		libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_strcmp.c\
		ft_printf/ft_printf.c ft_printf/ft_format.c ft_printf/ft_putstr.c\
		ft_printf/ft_putchar.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)
OBJB = $(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAME_B = checker

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(NAME_B)

clean:
	rm -f $(OBJS) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all
.SECONDARY:$(OBJS) $(OBJB)