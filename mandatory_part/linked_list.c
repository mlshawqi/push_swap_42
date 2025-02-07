#include "push_swap.h"

void    link_node(t_stack **head, int nbr)
{
    t_stack *new_node;
    t_stack  *current;
    
    new_node = malloc(sizeof(t_stack));
    if (!new_node) {
        return;
    }
    new_node->number = nbr;
    new_node->next = NULL;

    if (*head == NULL)
        *head = new_node;
    else
    {
        current = *head;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}

t_stack *ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}