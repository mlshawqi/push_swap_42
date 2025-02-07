#include "push_swap.h"

void    ft_loop_rotate(t_data *data, int pos)
{
    if(pos <= (data->size / 2))
    {
        while (pos > 0)
        {
            rb_rotate(&data->stack_b);
            pos--;
        }
    }
    else if (pos > (data->size / 2))
    {
        while (pos < data->size)
        {
            rrb_reverse_rotete(&data->stack_b);
            pos++;
        }
    }
}

void    ft_last_move(t_data *data)
{
    int i;
    int pos;
    t_stack *lst;

    i = data->size - 1;
    while(data->stack_b != NULL)
    {
        pos = 0;
        lst = data->stack_b;
        while(lst != NULL)
        {
            if(lst->number == data->arr[i])
            {
                ft_loop_rotate(data, pos);
                pa_push(data);
                break;
            }
            lst = lst->next;
            pos++;
        }
        i--;
    }
}

void    ft_stack_moves(t_data *data)
{
    int i;

    i = 0;
    while(data->stack_a != NULL)
    {
        if(data->stack_a->number < data->arr[i])
        {
            i++;
            pb_push(data);
            rb_rotate(&data->stack_b);
        }
        else if(((i + (data->chunk_size - 1)) < data->size) 
                && data->stack_a->number > data->arr[i + (data->chunk_size - 1)])
            ra_rotate(&data->stack_a);
        else
        {
            i++;
            pb_push(data);
        }
    }
    ft_last_move(data);
}
