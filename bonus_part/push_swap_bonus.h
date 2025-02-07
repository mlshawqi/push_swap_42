#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack{
    int number;
    struct s_stack *next;
}               t_stack;

typedef struct s_dataa{
    t_stack  *stack_a;
    t_stack  *stack_b;
    int size;
    int size_b;
    int *arr;
    int chunk_size;
}               t_data;


void    ft_parsing(int ac, char **av, t_data *data_a);
int	    ft_isnums(char *str);
int     count_strings(t_list *node, int len);
int     convert_strings(t_data *data, t_list *lst);
void    process_input(char **str, int ac, t_data *data);
int     ft_checkdupes(t_stack *stack_a);
int     ft_issort(t_stack *stack_a);

void    link_node(t_stack **head, int nbr);
t_stack *ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

void    ft_sort_main(t_data *data);
void    ft_sort_3(t_data *data, int min, int max);
void    ft_loop_rotate_a(t_data *data, int pos);
void    ft_sort_small(t_data *data);
void    min_nbr(t_data *data);

void    sa_swap(t_stack **data);
void    ra_rotate(t_stack **data);
void    rra_reverse_rotete(t_stack **data);
void    pa_push(t_data *data);

void    sb_swap(t_stack **data);
void    rb_rotate(t_stack **data);
void    rrb_reverse_rotete(t_stack **data);
void    pb_push(t_data *data);

void    sort_large(t_data *data);
void    ft_sort_arr(t_data *data);
void    ft_bubble_sort(int *arr, int size);
void    ft_loop_rotate(t_data *data, int pos);
void    ft_stack_moves(t_data *data);
void    ft_last_move(t_data *data);

void    ft_clear_exit(t_data *data);
void    ft_exit(t_data *d);
void	ft_stack_clear(t_stack **lst);
void	ft_stack_delone(t_stack *lst);

#endif