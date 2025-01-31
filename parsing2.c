#include "push_swap.h"


int     count_strings(t_list *node, int len)
{
    int i;
    int tlen;

    i = 0;
    tlen = 0;
    while(len)
    {
        i = 0;
        while(node->arr[i] != NULL)
        {
            i++;
            tlen++;
        }
        if(node->next)
            node = node->next;
        len--;
    }
    return (tlen);
}

int    convert_strings(t_data *data, t_list *lst)
{
    int i;
    int j;
    int error;

    i = 0;
    error = 0;
    while(i < data->size)
    {
        j = 0;
        while(lst->arr[j] != NULL)
        {
            link_node(&data->stack_a, ft_atoi(lst->arr[j], &error));
            if(error == 1)
                return (0);
            i++;
            j++;
        }
        if(lst->next)
            lst = lst->next;
    }
    return (1);
}

void    process_input(char **str, int ac, t_data *data)
{
    int i;
    t_list  *node;
    int len;

    node = NULL;
    i = 1;
    len = 0;
    while(i < ac)
    {
        add_node(&node, ft_split(str[i], ' '));
        i++;
        len++;
    }
    data->size = count_strings(node, len);
    // stack_a->stack = malloc(sizeof(int) * stack_a->size);
    // if(!stack_a->stack)
    // {
    //     ft_lstclear(&node);
    //     exit(0);
    // }
    if(!convert_strings(data, node))
    {
        ft_lstclear(&node);
        ft_exit(data);
    }
    ft_lstclear(&node);
}