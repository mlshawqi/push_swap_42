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
    exit (0);
}

int main(int argc, char *argv[])
{
    t_data  data;

    data.stack_a = NULL;
    data.stack_b = NULL;
    ft_parsing(argc, argv, &data);

    if(data.size == 3)
        ft_sort_main(&data);
    // if(stacka.size == 5)
    //     ft_sort_5(&stacka, &stackb);

    t_stack *node = data.stack_a;
    while(node != NULL)
    {
        printf("%d\n", node->number);
        node = node->next;
    }
    printf("nice %d\n", data.size);
    if(data.stack_a)
        ft_stack_clear(&data.stack_a);
}