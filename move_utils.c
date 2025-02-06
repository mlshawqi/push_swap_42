#include "push_swap.h"

void    ft_last_move(t_data *data)
{
    int i;
    int pos;
    t_stack *lst;

    i = 0;
    while(data->stack_b != NULL)
    {
        pos = 0;
        lst = data->stack_b;
        while(lst != NULL)
        {
            if(data->stack_b->number == data->arr[i])
            {
                if(pos <= (data->size / 2))
                {
                    while (pos-- > 0)
                        rb_rotate(&data->stack_b);
                }
                else if (pos > (data->size / 2))
                {
                    while (pos++ < data->size)
                        rrb_reverse_rotete(&data->stack_b);
                }                
                pa_push(data);
                break;
            }
            lst = lst->next;
            pos++;
        }
        i++;
    }
}

void     ft_moves(t_data *data, int *move_chunk)
{
    if(data->stack_a->number < data->chunk[0])
    {
        pb_push(data);
        rb_rotate(&data->stack_b);
        (*move_chunk)++;
    }
    else if(data->stack_a->number > data->chunk[data->chunk_size - 1])
        ra_rotate(&data->stack_a);
    else
    {
        pb_push(data);
        (*move_chunk)++;
    }
}

void    ft_stack_moves(t_data *data)
{
    int i;

    i = 0;
    while(data->stack_a != NULL)
    {
        if(data->stack_a->number < data->chunk[0])
        {
            i++;
            pb_push(data);
            rb_rotate(&data->stack_b);
            ft_chunk(data, data->arr + i, data->chunk_size);
        }
        else if(data->stack_a->number > data->chunk[data->chunk_size - 1])
            ra_rotate(&data->stack_a);
        else
        {
            i++;
            pb_push(data);
            ft_chunk(data, data->arr + i, data->chunk_size);
        }
        // printf("===ch %d  nb %d\n", data->chunk[data->chunk_size - 1], data->stack_a->number);
        // data->stack_a = data->stack_a->next;
    }
    // ft_last_move(data);
}
