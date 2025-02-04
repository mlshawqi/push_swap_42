#include "push_swap.h"

int     ft_moves(t_data *data)
{
    int i;
    int move_chunk;

    move_chunk = 0;
    i = 0;
    while(data->chunk[i] != '\0')
    {
        if(data->stack_a->number == data->chunk[i])
        {
            pb_push(data);
            move_chunk++;
            break;
        }
        else if(data->stack_a->number > data->chunk[i])
        {
            ra_rotate(data->stack_a);
            break;
        }
        else if(data->stack_a->number < data->chunk[i])
        {
            pb_push(data);
            rb_rotate(data->stack_b);
            move_chunk++;
            break;
        }
        i++;
    }
    return (move_chunk);
}

void    ft_stack_moves(t_data *data)
{
    int move_chunk;

    while(data->stack_a != NULL)
    {
        move_chunk = ft_moves(data);
        if (move_chunk > 0)
            ft_chunk(data, data->arr + 1, data->chunk_size);
        data->stack_a = data->stack_a->next;
    }
}