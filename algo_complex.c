#include "push_swap.h"

void    ft_chunk(t_data *data,int *arr, int count)
{
    int i;

    data->chunk = malloc(sizeof(int) * count);
    if(!data->chunk)
        ft_exit(data);
    i = 0;
    while(i < count)
    {
        data->chunk[i] = arr[i];
        i++;
    }
    for(int i = 0; i < count; i++)
        printf("--chunk = %d\n", data->chunk[i]);
}

void     ft_bubble_sort(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while(i < size)
    {
        j = 0;
        while(j < (size - i - 1))
        {
            if(arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

void    ft_sort_arr(t_data *data)
{
    t_stack *lst;
    int i;

    data->arr = malloc(data->size * sizeof(int));
    if(!data->arr)
        ft_exit(data);
    lst = data->stack_a;
    i = 0;
    while(lst != NULL)
    {
        data->arr[i] = lst->number;
        lst = lst->next;
        i++;
    }
    ft_bubble_sort(data->arr, data->size);
}

void    sort_large(t_data *data)
{
    ft_sort_arr(data);
    if (data->size >= 6 && data->size <= 15)
        data->chunk_size = 3;
    else if (data->size <= 100)
        data->chunk_size = 13;
    else if (data->size)
        data->chunk_size = 30;
    else
        data->chunk_size = 45;
    ft_chunk(data, data->arr, data->chunk_size);
    ft_stack_moves(data);
}