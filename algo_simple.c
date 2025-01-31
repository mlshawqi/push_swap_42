#include "push_swap.h"

void    ft_sort_3(t_data *data, int min, int max)
{
    if(min == data->stack_a->next->number && max == data->stack_a->next->next->number)
        sa_swap(&data->stack_a);
    else if(min == data->stack_a->next->number && max == data->stack_a->number)
        ra_rotate(&data->stack_a);
    // else if(min == data->stack[2] && max == data->stack[1])
    //     rra_reverse_rotete(data);
    // else if(min == data->stack[2] && max == data->stack[0])
    // {
    //     sa_swap(data);
    //     rra_reverse_rotete(data);
    // }
    else if(min == data->stack_a->number && max == data->stack_a->next->number)
    {
        sa_swap(&data->stack_a);
        ra_rotate(&data->stack_a);
    }
}

void    ft_sort_main(t_data *data)
{
    int min;
    int max;
    t_stack *node;

    min = data->stack_a->number;
    max = data->stack_a->number;
    node = data->stack_a;
    while(node != NULL)
    {
        if(node->number < min)
            min = node->number;
        else if(node->number > max)
            max = node->number;
        node = node->next;
    }
    ft_sort_3(data, min, max);
}

// void    ft_sort_5(t_data *stack_a, t_data *stack_b)
// {
//     stack_b->stack = ft_calloc(stack_a->size, sizeof(int));
//     stack_b->size = stack_a->size;
    

// }