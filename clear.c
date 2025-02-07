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
void    ft_clear_exit(t_data *data)
{
    if(data->stack_a)
        ft_stack_clear(&data->stack_a);
    if(data->stack_b)
        ft_stack_clear(&data->stack_b);
    if(data->arr)
        free(data->arr);
    exit (0);
}

void    ft_exit(t_data *d)
{
    ft_printf("Error\n");
    ft_clear_exit(d);
}