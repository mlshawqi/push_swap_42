#include "push_swap_bonus.h"

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
        ft_clear_exit(data);
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

void    ft_cmp_stack(t_data *data)
{
    int i;

    i = 0;
    while(data->stack_a != NULL)
    {
        if(data->stack_a->number == data->arr[i])
            i++;
        else
        {
            ft_printf("KO\n");
            ft_clear_exit(data);
        }
        data->stack_a = data->stack_a->next;
    }
    ft_printf("OK\n");
}