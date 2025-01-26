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

int    convert_strings(t_data *d, t_list *lst)
{
    int i;
    int j;
    int error;

    i = 0;
    error = 0;
    while(i < d->size)
    {
        j = 0;
        while(lst->arr[j] != NULL && i < d->size)
        {
            d->arr[i] = ft_atoi(lst->arr[j], &error);
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

void    process_input(char **str, int ac, t_data *d)
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
    d->size = count_strings(node, len);
    d->arr = malloc(sizeof(int) * d->size);
    if(!d->arr)
        ft_lstclear(&node);
    if(!convert_strings(d, node))
    {
        ft_lstclear(&node);
        ft_exit(d);
    }
    ft_lstclear(&node);
}