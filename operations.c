#include "push_swap.h"

void    sa_swap(t_stack **data)
{
    t_stack *tmp;

    tmp = *data;
    *data = (*data)->next;
    tmp->next = (*data)->next;
    (*data)->next = tmp;
    ft_printf("sa\n");
}

void    ra_rotate(t_stack **data)
{
    t_stack *last_node;
    t_stack *head;

    head = (*data)->next;
    last_node = ft_lstlast(*data);
    last_node->next = *data;
    (*data)->next = NULL;
    *data = head;
    ft_printf("ra\n");
}

void    rra_reverse_rotete(t_stack **data)
{
    t_stack *last_node;
    t_stack *head;

    head = *data;
    while(*data != NULL)
    {
        if((*data)->next->next == NULL)
        {
            last_node = (*data)->next;
            (*data)->next->next = head;
            (*data)->next = NULL;
        }
        *data = (*data)->next;
    }
    *data = last_node;
    ft_printf("rra\n");
}

void    pb_push(t_data *data)
{
    t_stack *first_node;

    first_node = data->stack_a;
    data->stack_a = data->stack_a->next;
    ft_lstadd_front(&data->stack_b, first_node);
    data->size--;
    data->size_b++;
    ft_printf("pb\n");
}

void    pa_push(t_data *data)
{
    t_stack *first_node;

    first_node = data->stack_b;
    data->stack_b = data->stack_b->next;
    ft_lstadd_front(&data->stack_a, first_node);
    data->size_b--;
    data->size++;
    ft_printf("pa\n");
}