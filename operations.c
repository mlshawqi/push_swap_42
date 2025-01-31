#include "push_swap.h"

void    sa_swap(t_stack **data)
{
    (*data)->next

    tmp = (*data)->number;
    (*data)->number = (*data)->next->number;
    (*data)->next->number = tmp;
    ft_printf("sa\n");
}

void    ra_rotate(t_stack **data)
{
    t_stack *last_node;
    t_stack *head;

    head = *data;
    while(data != NULL)
    {
        if((*data)->next->next == NULL)
        {
            last_node = data->next;
            data->next->next == head;
            data->next == NULL;
        }
        data = data->next;
    }
    data = last_node;
    ft_printf("ra\n");
}

// void    rra_reverse_rotete(t_data *data)
// {
//     int i;
//     int tmp;

//     i = data->size - 1;
//     tmp = data->stack[data->size - 1];
//     while(i > 0)
//     {
//         data->stack[i] = data->stack[i - 1];
//         i--;
//     }
//     data->stack[0] = tmp;
//     ft_printf("rra\n");
// }