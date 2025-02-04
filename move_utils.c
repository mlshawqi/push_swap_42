#include "push_swap.h"

void     ft_moves(t_data *data, int *move_chunk)
{
    int i;

    i = 0;
    (*move_chunk) = 0;
    while (i < data->chunk_size)
    {
        // printf("=========chunk %d   nbr %d\n", data->chunk[i], data->stack_a->number);
        if(data->stack_a->number == data->chunk[i])
        {
            pb_push(data);
            (*move_chunk)++;
            return ;
        }
        i++;
    }
    if(data->stack_a->number < data->chunk[0])
    {
        pb_push(data);
        rb_rotate(&data->stack_b);
        (*move_chunk)++;
        return;
    }
    else if(data->stack_a->number > data->chunk[data->chunk_size - 1])
        ra_rotate(&data->stack_a);
}

void    ft_stack_moves(t_data *data)
{
    int move_chunk;
    int i = 0;

    while(i < data->size)
    {
        move_chunk = 0;
        ft_moves(data, &move_chunk);
        if (move_chunk > 0)
            ft_chunk(data, data->arr + 1, data->chunk_size);
        // printf("---ch %d  nb %d\n", move_chunk, data->stack_a->number);
        // data->stack_a = data->stack_a->next;
        i++;
    }
}
