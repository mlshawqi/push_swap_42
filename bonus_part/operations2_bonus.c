#include "push_swap_bonus.h"

void    sb_swap(t_stack **data)
{
    t_stack *tmp;

    if (!data || !(*data) || !(*data)->next)
        return;
    tmp = *data;
    *data = (*data)->next;
    tmp->next = (*data)->next;
    (*data)->next = tmp;
}

void    rb_rotate(t_stack **data)
{
    t_stack *last_node;
    t_stack *head;

    if (!data || !(*data) || !(*data)->next)
        return;
    head = (*data)->next;
    last_node = ft_lstlast(*data);
    last_node->next = *data;
    *data = head;
    last_node->next->next = NULL;
}

void    rrb_reverse_rotete(t_stack **data)
{
    t_stack *prev;
    t_stack *last_node;

    if (!data || !(*data) || !(*data)->next)
        return;
    prev = NULL;
    last_node = *data;
    while (last_node->next)
    {
        prev = last_node;
        last_node = last_node->next;
    }
    prev->next = NULL;
    last_node->next = *data;
    *data = last_node;
}

void    pb_push(t_data *data)
{
    t_stack *first_node;

    if (!data || !data->stack_a)
        return ;
    first_node = data->stack_a;
    data->stack_a = data->stack_a->next;
    first_node->next = NULL;
    ft_lstadd_front(&data->stack_b, first_node);
    data->size_b++;
}