#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
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
    int *chunk;
}               t_data;


void    ft_exit(t_data *d);
void    ft_parsing(int ac, char **av, t_data *data_a);
int	ft_isnums(char *str);
int     count_strings(t_list *node, int len);
int    convert_strings(t_data *data, t_list *lst);
void    process_input(char **str, int ac, t_data *data);
void    link_node(t_stack **head, int nbr);
void	ft_stack_clear(t_stack **lst);
void	ft_stack_delone(t_stack *lst);
int    ft_checkdupes(t_stack *stack_a);
int    ft_issort(t_stack *stack_a);

t_stack *ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

void    ft_sort_main(t_data *data);
void    ft_sort_3(t_data *data, int min, int max);

void    sa_swap(t_stack **data);
void    ra_rotate(t_stack **data);
void    rra_reverse_rotete(t_stack **data);
void    pb_push(t_data *data);
void    pa_push(t_data *data);

void    ft_sort_small(t_data *data);
void    min_nbr(t_data *data);

void    sort_large(t_data *data);
void    ft_sort_arr(t_data *data);
void     ft_bubble_sort(int *arr, int size);
void    ft_chunk(t_data *data,int *arr, int count);

#endif