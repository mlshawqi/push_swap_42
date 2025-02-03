#include "push_swap.h"

void	ft_stack_delone(t_stack *lst)
{
	if (lst == NULL)
		return ;
	free(lst);
}

void	ft_stack_clear(t_stack **lst)
{
	t_stack	*p;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		p = (*lst)->next;
		ft_stack_delone(*lst);
		*lst = p;
	}
	*lst = NULL;
}

void    ft_exit(t_data *d)
{
    ft_printf("Error\n");
    if(d->stack_a)
        ft_stack_clear(&d->stack_a);
    if(d->stack_b)
        ft_stack_clear(&d->stack_b);
    if(d->arr)
        free(d->arr);
    exit (2);
}

int main(int argc, char *argv[])
{
    t_data  data;

    data.stack_a = NULL;
    data.stack_b = NULL;
    data.arr = NULL;
    data.size = 0;
    data.size_b = 0;
    ft_parsing(argc, argv, &data);
    if(data.size == 5 || data.size == 4 || data.size == 3 || data.size == 2)
        ft_sort_small(&data);
    else
        sort_large(&data);

//--------------------------------
    for(int i = 0; i < data.size; i++)
        printf("arr = %d\n", data.arr[i]);

    // t_stack *node = data.stack_a;
    // while(node != NULL)
    // {
    //     printf("%d\n", node->number);
    //     node = node->next;
    // }
    // printf("---------------\n");
    // node = data.stack_b;
    // while(node != NULL)
    // {
    //     printf("%d\n", node->number);
    //     node = node->next;
    // }
    printf("nice\n");
    // pb_push(&data);
    // pb_push(&data);
    // node = data.stack_b;
    // while(node != NULL)
    // {
    //     printf("%d\n", node->number);
    //     node = node->next;
    // }
    // printf("------%d>> %d\n", data.size, data.size_b);
    // node = data.stack_a;
    // while(node != NULL)
    // {
    //     printf("%d\n", node->number);
    //     node = node->next;
    // }
    ft_exit(&data);
}